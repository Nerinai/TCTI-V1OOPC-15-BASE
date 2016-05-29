#include "hwlib.hpp"
#include "stdio.h"

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

void input (hwlib::port_out &leds, hwlib::target::pin_in &buton1, hwlib::target::pin_in &buton2){
	int amount = 0;
	unsigned int dummy = 0;
	while(1){
		if ( ! buton1.get()){
			amount++;
			if (amount <= 4){
				for (int i = 0; i < amount; i++){
					dummy = dummy | 1 << i;
				}
			}
			if (amount > 4){
				amount = 4;
			}
			hwlib::wait_ms(300);
		}
		if ( ! buton2.get()){
			amount--;
			if (amount >= 0){
				//for (int i = amount; i > 0; i--){
					dummy = dummy >> 1 & 0x0F;
				//}
			}
			if (amount < 0){
				amount = 0;
			}
			hwlib::wait_ms(300);
		}
		leds.set(dummy);
		
		
		
		
	}
}

int main(void)
{
// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto buton1 = target::pin_in  (target::pins::d6);
	auto buton2 = target::pin_in  (target::pins::d7);
	auto led0 	= target::pin_out (target::pins::d8);
	auto led1 	= target::pin_out (target::pins::d9);
	auto led2 	= target::pin_out (target::pins::d10);
	auto led3 	= target::pin_out (target::pins::d11);
	
 
	auto leds 		= hwlib::port_out_from_pins(led0, led1, led2, led3);
	
	
	
	
	input (leds, buton1, buton2);
	
	return 0;
}