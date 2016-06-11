#include "RC522.hpp"
#include "nfccontroler.hpp"
#include "Mifare_Classic.hpp"
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
	
	bool card = false;
	bool select_success = false;
	byte cardtype[2];
	byte key[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
	byte key2[] = {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7};
	byte writesector[3][16] = {{0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5},
							   {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7},
							   {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
	byte sectoraddr = 0x00;
	byte sectoraddr2 = 0x04;
	byte sector[4][16];
	byte sector2[4][16];
	byte serial[4];
	//byte keya = 0x60;
	nfc.init_chip();
	card = reader.iscard(cardtype);
	
	if (card == true){
		select_success = reader.select_card(serial);
	}
	
	if (select_success == true){
		reader.writeSector(4, writesector, 0x60, &sectoraddr2, key2, serial);
		reader.readSector(4, sector, 0x60, &sectoraddr, key, serial);
		reader.readSector(4, sector2, 0x60, &sectoraddr2, key2, serial);
	}
	
	/*for(int i = 0; i < 4; i++){
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
	
	/*//byte key [] = {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7};
	//byte data[] = {0x06, 0x57, 0x80, 0x58, 0x65};
	//byte key[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	byte cardtype[2];
	byte serial[4];
	byte sector = 0x00;
	byte block1 = 0x00;
	byte block2 = 0x01;
	byte block3 = 0x02;
	byte block4 = 0x03;
	byte data1[16] = {};
	byte data2[16] = {};
	byte data3[16] = {};
	byte data4[16] = {};
	
	nfc.init_chip();
	card = reader.iscard(cardtype);
	
	if (card == true){
		select_success = reader.select_card(serial);
	}
	
	if (select_success == true){
		reader.authenticate_classic((byte)RC522::Keytype::AuthwithA, &sector, key, serial);
		//nfc.writeBlock(sector, data, 5);
		reader.readblock(block1, data1);
		reader.readblock(block2, data2);
		reader.readblock(block3, data3);
		reader.readblock(block4, data4);
	}
	
	
	for (int i = 0; i < 16; i++){
		hwlib::cout << hwlib::hex << hwlib::setfill('0') << hwlib::setw(2) << (int)data1[i] << ' ';
	}
	hwlib::cout << '\n';
	for (int i = 0; i < 16; i++){
		hwlib::cout << hwlib::hex << hwlib::setfill('0') << hwlib::setw(2) << (int)data2[i] << ' ';
	}
	hwlib::cout << '\n';
	for (int i = 0; i < 16; i++){
		hwlib::cout << hwlib::hex << hwlib::setfill('0') << hwlib::setw(2) << (int)data3[i] << ' ';
	}
	hwlib::cout << '\n';
	for (int i = 0; i < 16; i++){
		hwlib::cout << hwlib::hex << hwlib::setfill('0') << hwlib::setw(2) << (int)data4[i] << ' ';
	}
	hwlib::cout << '\n';*/
	//nfc.cardPoll();
	
	/*byte array[] = {0xFF, 0xAA, 0xBB};
	int result[64];
	
	nfc.writeFIFO(3, array);
	int n = nfc.readFIFO(result);
	
	for (int i = 0; i < n; i++){
		hwlib::cout << hwlib::hex << result[i] << ' ';
	}*/
	/*
	hwlib::cout << hwlib::hex << (int)nfc.readRegister(RC522::FIFODataReg) << ' ';
	hwlib::cout << hwlib::hex << (int)nfc.readRegister(RC522::FIFOLevelReg) << ' ';
	hwlib::cout << hwlib::hex << (int)nfc.readRegister(RC522::FIFODataReg) << ' ';
	hwlib::cout << hwlib::hex << (int)nfc.readRegister(RC522::FIFOLevelReg) << ' ';
	hwlib::cout << hwlib::hex << (int)nfc.readRegister(RC522::FIFODataReg) << ' ';
	hwlib::cout << hwlib::hex << (int)nfc.readRegister(RC522::FIFOLevelReg) << ' ';*/
	
	return 0;
}