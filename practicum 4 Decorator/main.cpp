#include "hwlib.hpp"

class pin_in_and_gate : public hwlib::pin_in{
private:
	hwlib::pin_in & pin1;
	hwlib::pin_in & pin2;
public:
	pin_in_and_gate(hwlib::pin_in & pin1, hwlib::pin_in & pin2):
	pin1(pin1), pin2(pin2){}
	
	bool get() override {
		if ( (! pin1.get()) && (! pin2.get()) ){
			return 1;
		}
		else{
			return 0;
		}
	return 0;
	}
};

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
	
	auto buton1 = target::pin_in  (target::pins::d6);
	auto butona = target::pin_in  (target::pins::d7);
	
	pin_in_and_gate gate (buton1, butona);
	
	while(1){
		if(gate.get()){
			hwlib::cout << hwlib::left  << " Hello world\n";
			hwlib::wait_ms(300);
		}
	}
	return 0;
}