#include "nfccontroler_all.hpp"

class Stand
{
private:
	byte standid;
	byte standsector;
	byte * sectorkey;
	RC522 & controller;
	Mifare_Classic & protocol;
public:
	Stand(byte standid, byte standsector, byte * sectorkey, RC522 & controller, Mifare_Classic & protocol):
	standid(standid), standsector(standsector), sectorkey(sectorkey), controller(controller), protocol(protocol)
	{}
	
	union timestamp{
		long long int as_l_l_int;
		byte 		  as_byte_array[8] = {};
	}timestamp;
	
	void set_standid(byte id){
		standid = id;
	}
	
	byte get_standid(void){
		return standid;
	}
	
	void set_standsector(byte sector){
		standsector = sector;
	}
	
	byte get_standsector(void){
		return standsector;
	}
	
	long long int timer (void){
		return hwlib::now_us();
	}
	
	void read_timestamp (void){
		byte sector [4][16] = {};
		byte cardtype[2];
		byte serial[4];
		controller.initChip();
		
		if(protocol.isCard(cardtype)){
			if(protocol.selectCard(serial)){
				if(protocol.readSector(4, sector, 0x60, &standsector, sectorkey, serial)){
					for (int i = 0; i < 8; i++){
						timestamp.as_byte_array[i] = sector[1][i];
					}
				}
			}
		}
		long long int time = timestamp.as_l_l_int;
		
		hwlib::cout << hwlib::dec << time << '\n';
	}
	
	void standTimeStamp (void){
		byte cardtype[2];
		byte serial[4];
		byte block = standsector;
		timestamp.as_l_l_int = timer();
		controller.initChip();
		
		if(protocol.isCard(cardtype)){
			if(protocol.selectCard(serial)){
				if(protocol.authenticateSector(0x60, &standsector, sectorkey, serial)){
					protocol.writeBlock(standsector, &standid, 1);
					protocol.writeBlock(++block, timestamp.as_byte_array, 8);
				}
			}
		}
	}

};

int main(void){
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	hwlib::wait_ms(500);
	
	target::pin_out sda  (target::pins::d22);
	target::pin_out sck  (target::pins::d24);
	target::pin_out mosi (target::pins::d26);
	target::pin_in  miso (target::pins::d28);
	target::pin_in_out reset (target::pins::d30);
	
	hwlib::spi_bus_bit_banged_sclk_mosi_miso spi (
	sck,
	mosi,
	miso
	);
	
	RC522 nfc (sda, reset, spi);
	Mifare_Classic reader (nfc);
	
	nfc.selfTest();
	
	byte stand1_key[] = {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7};
	
	Stand stand1 (0x01, 0x08, stand1_key, nfc, reader);
	Stand stand2 (0x02, 0x0C, stand1_key, nfc, reader);
	
	stand1.timer();
	while(1){
		hwlib::wait_ms(300);
		stand1.standTimeStamp();
		hwlib::wait_ms(300);
		stand2.standTimeStamp();
		hwlib::wait_ms(300);
		stand1.read_timestamp();
		stand2.read_timestamp();
	}
	/*bool card = false;
	bool select_success = false;
	byte cardtype[2];
	byte key[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
	byte key[] = {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7};
	byte writesector[3][16] = {{0xFF, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5},
							   {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7},
							   {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
	byte sectoraddr = 0x00;
	byte sectoraddr2 = 0x04;
	byte sector[4][16];
	byte sector2[4][16];
	byte serial[4];
	//byte keya = 0x60;
	nfc.initChip();
	card = reader.isCard(cardtype);
	
	if (card == true){
		select_success = reader.selectCard(serial);
	}
	
	if (select_success == true){
		reader.writeSector(4, writesector, 0x60, &sectoraddr2, key2, serial);
		reader.readSector(4, sector, 0x60, &sectoraddr, key, serial);
		reader.readSector(4, sector2, 0x60, &sectoraddr2, key2, serial);
	}
	
	for(int i = 0; i < 4; i++){
		for (int j = 0; j < 16; j++){
			hwlib::cout << hwlib::hex << hwlib::setfill('0') << hwlib::setw(2) << (int)sector[i][j] << ' ';
		}
		hwlib::cout << '\n';
	}
	hwlib::cout << '\n';
	for(int i = 0; i < 4; i++){
		for (int j = 0; j < 16; j++){
			hwlib::cout << hwlib::hex << hwlib::setfill('0') << hwlib::setw(2) << (int)sector2[i][j] << ' ';
		}
		hwlib::cout << '\n';
	}*/
	return 0;
}