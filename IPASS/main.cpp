#include "hwlib.hpp"

int main (void){
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	int i = 191;
	
/*	namespace target = hwlib::target;

	auto IRQ = target::pin_out (target::pins::d22);
	auto SDA = target::pin_out (target::pins::d24);
	auto RESET = target::pin_in_out (target::pins::d26);
	auto SCL = target::pin_out (target::pins::d28);
	auto MOSI = target::pin_out (target::pins::d30);
	auto MISO = target::pin_in (target::pins::d32);
	
	auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
	SCL,
	MOSI,
	MISO
	);
	
	RC522 blah (IRQ, SDA, RESET, spi);
	blah.get_version();*/
	
	hwlib::cout << hwlib::hex << i;
	
	return 0;
}