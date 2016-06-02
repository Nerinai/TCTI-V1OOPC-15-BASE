#include "RC522.hpp"
int main(void){
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	target::pin_out sda  (target::pins::d22);
	target::pin_out sck  (target::pins::d24);
	target::pin_out mosi (target::pins::d26);
	target::pin_in  miso (target::pins::d28);
	
	hwlib::spi_bus_bit_banged_sclk_mosi_miso spi (
	sck,
	mosi,
	miso
	);
	
	RC522 nfc (sda, spi);
	
	hwlib::wait_ms(1000);
	
	nfc.cardPoll();
	
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