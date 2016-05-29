#include "hwlib.hpp"

void kitt( hwlib::port_out & leds, int ms = 80){
	for(;;){
		for (unsigned int i = 0; i < leds.number_of_pins() -1; i++){
			leds.set(0x03 << i);
			hwlib::wait_ms( ms );
		}
		for (unsigned int i = leds.number_of_pins() -3; i > 0; --i){
			leds.set(0x03 << i);
			hwlib::wait_ms ( ms );
		}
	}
}

int main(void)
{
// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto led0 = target::pin_out (target::pins::d8);
	auto led1 = target::pin_out (target::pins::d9);
	auto led2 = target::pin_out (target::pins::d10);
	auto led3 = target::pin_out (target::pins::d11);
	
	auto leds = hwlib::port_out_from_pins(led0, led1, led2, led3);
	::kitt(leds, 500);
	
	return 0;
}