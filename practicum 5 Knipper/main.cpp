#include "hwlib.hpp"
#include "stdio.h"

void kitt( hwlib::port_out & leds, int ms = 80){
	for(;;){
		for (unsigned int i = 0; i < leds.number_of_pins() -1; i++){
			leds.set(0x01 << i);
			hwlib::wait_ms( ms );
		}
		for (unsigned int i = leds.number_of_pins() -3; i > 0; --i){
			leds.set(0x01 << i);
			hwlib::wait_ms ( ms );
		}
	}
}

class pin_out_invert : public hwlib::pin_out{
private:
	hwlib::pin_out & slave;
	
public:
	pin_out_invert(hwlib::pin_out & slave):
	slave(slave){}
	
	void set( bool v ) override{
		if (v){
			slave.set(0);
		}
		else{
			slave.set(1);
		}
	}
};

int main(void)
{
// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto ds		= target::pin_out (target::pins::d3);
	auto stcp	= target::pin_out (target::pins::d4);
	auto shcp	= target::pin_out (target::pins::d5);
	auto led0 	= target::pin_out (target::pins::d8);
	auto led1 	= target::pin_out (target::pins::d9);
	auto led2 	= target::pin_out (target::pins::d10);
	auto led3 	= target::pin_out (target::pins::d11);
	
	auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
	stcp,
	ds,
	hwlib::pin_in_dummy
	);
	
	auto hc595 = hwlib::hc595(spi, shcp);
	
	auto allpins = target::pin_out_all (led0, led1, led2, led3, hc595.p3, hc595.p2, hc595.p1, hc595.p0);
	auto set1 = target::pin_out_all (led0, led1, led2, led3);
	auto set2 = target::pin_out_all (hc595.p3, hc595.p2, hc595.p1, hc595.p0);
	auto invertset1 = ::pin_out_invert(set1);
	auto invertset2 = ::pin_out_invert(set2);
	
	allpins.set(0);
	
	auto leds = hwlib::port_out_from_pins (invertset1, invertset2);
	hwlib::kitt(leds, 5000);
	
	return 0;
}