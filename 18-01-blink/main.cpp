// ==========================================================================
//
// blink a led on PIOB pin 27 == arduino-due on-board LED
//
// This file is in the public domain.
//
// ==========================================================================

//! [[Doxygen blink example]]
#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
<<<<<<< HEAD
   auto snookums = hwlib::target::pins::led;
   
   auto lamp = hwlib::target::pin_out(snookums);
   while(1){
      lamp.set( 1 );
      hwlib::wait_ms( 200 );
      lamp.set( 0 );
      hwlib::wait_ms( 200 );
	
=======
   auto led = hwlib::target::pin_out( hwlib::target::pins::led );
   while(1){
      led.set( 1 );
      hwlib::wait_ms( 200 );
      led.set( 0 );
      hwlib::wait_ms( 200 );      
>>>>>>> upstream/master
   }
}
//! [[Doxygen blink example]]

