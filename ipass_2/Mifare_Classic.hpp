#ifndef MIFARE_CLASSIC_HPP
#define MIFARE_CLASSIC_HPP
#include "nfccontroler_limited.hpp"

class Mifare_Classic : public nfccontroler_limited {
private:
	nfccontroler_limited & slave;
public:
	Mifare_Classic(nfccontroler_limited & slaaf): 
	slave(slaaf){}
	
	
	bool trancieve(const byte * data_in, const int data_in_lenght, byte * data_out, int * data_out_lenght, bool crc = false, bool REQA = false) override {
		return slave.trancieve(data_in, data_in_lenght, data_out, data_out_lenght, crc, REQA);
	}
	
	bool authent(const byte * data_in, const int data_in_lenght){
		return slave.authent(data_in, data_in_lenght);
	}
	
	void checkErroAndIrq (byte * result)override{
		slave.checkErroAndIrq(result);
	}
	
	bool iscard (byte * cardtype) override {
		byte reqa = 0x26;
		bool card = false;
		while(card == false){
			hwlib::wait_ms(333);
			card = trancieve(&reqa, 1, cardtype, nullptr, false, true);
		}
		return true;
	}
	
	bool select_card(byte * Cardserial) override {
		
		byte Get_UID[2] =  {0x93, 0x20};
		byte Sel_card[7] = {0x93, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00};
		byte UID[5];
		byte Sak[3];
		byte CRCcheck[2];
		int SAK_size;
		int UID_lenght;
		
		trancieve(Get_UID, 2, UID, &UID_lenght, false, false);
		
		byte CRC_A = UID[0] ^ UID[1] ^ UID[2] ^ UID[3];
		if (UID[4] != CRC_A){
			hwlib::cout << "Could not select card. UID-CRC does not match expected.\n";
			return false;
		}
		
		hwlib::wait_ms(333);
		
		for(int i = 0; i < 5; i++){
			Sel_card[i + 2] = UID[i];
		}
		
		
		trancieve(Sel_card, 7, Sak, &SAK_size, true, false);
		
		calculateCRC(&Sak[0], 1, CRCcheck);
		
		if(Sak[0] == 0x08){
			if((Sak[1] != CRCcheck[0]) || (Sak[2] != CRCcheck[1])){
				hwlib::cout << "Selection error. Sak CRC does not match expected";
			return false;
			}
			
		} else {
			hwlib::cout << "No valid SAK response";
			return false;
		}
		
		for(int i = 0; i < 4; i++){
			Cardserial[i] = UID[i];
		}
		hwlib::cout << "Card selected\n";
		return true;
	}
	
	bool authenticate_classic(byte typekey, byte * block_address, byte * key, byte * Cardserial) override {
		int n = 2;
		byte auth[12];
		byte errandirq[2];
		auth[0] = typekey;
		auth[1] = *block_address;
		
		for(int i = 0; i < 6; i++ ){
			auth[n] = key[i];
			n++;
		}
		
		for(int i = 0; i < 4; i++){
			auth[n] = Cardserial[i];
			n++;
		}
		
		if (n > 13){
			hwlib::cout << "Authentication error, to much data\n";
			return false;
		}
		
		authent(auth, 12);
		
		checkErroAndIrq(errandirq);
		
		if((errandirq[0] == 0x14) && (errandirq[1] == 0x00)){
			hwlib::cout << "Authentication Successfull\n";
			return true;
		} else {
			hwlib::cout << "Authentication Unsuccessfull\n";
			return false;
		}
		
		return true;
	}
	
	bool readblock(byte block_address, byte * data_out) override {
		byte read[2] = {0x30, block_address};
		byte Intermediate[18];
		byte data_crc[2];
		byte check_crc[2];
		byte data[16];
		
		trancieve(read, 2, Intermediate, nullptr, true, false);
		
		for (int i = 0; i < 16; i++){
			data[i] = Intermediate[i];
		}
		
		for (int i = 0; i < 2; i++){
			data_crc[i] = Intermediate[i + 16];
		}
		
		calculateCRC(data, 16, check_crc);
		
		for (int i = 0; i < 2; i++){
			if(data_crc[i] != check_crc[i]){
				hwlib::cout << "CRC of recieved data does not match\n";
				return false;
			}
		}
		
		for (int i = 0; i < 16; i++){
			data_out[i] = data[i];
		}
		
		return true;
	}
	
	bool writeBlock(const byte block_address,const byte * data_in,const int lenght) override {
		byte read[2] = {0xA0, block_address};
		byte Ack, Ack2;
		byte appended_data[16] = {};
		
		trancieve(read, 2, &Ack, nullptr, true, false);
		
		if (Ack != 0x0A){
		
			hwlib::cout << "Write error did not recieve acknowledge after selecting the block to be written to.\n";
			return false;
		}
		
		if ( lenght < 16){
			
			for (int i = 0; i < lenght; i++){
				appended_data[i] = data_in[i];
			}
		}
		
		trancieve(appended_data, 16, &Ack2, nullptr, true, false);
		
		
		if (Ack != 0x0A){
		
			hwlib::cout << "Write error did not recieve acknowledge after the data was written.\n";
			return false;
		}
		
		return true;
	}
	
	int calculateCRC (const byte * data, const int length, byte * result){
		return slave.calculateCRC(data, length, result);
	}

};

#endif // MIFARE_CLASSIC_HPP
