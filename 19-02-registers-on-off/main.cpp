// ==========================================================================
//
// toggle a led
// switch on PC0
//
// This file is in the public domain.
//
// ==========================================================================

#include "sam.h"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // make the GPIO pin an output
   PIOB->PIO_OER = 0x01 << 27;
   
   //bool LED = false;
   //bool switch = true;
   
   for(;;){
         
      // wait some time
      for( volatile int i = 0; i < 1'000; i++ ){}
      
      if( PIOB->PIO_OER)
      
      // make the GPIO pin low
      PIOB->PIO_CODR = 0x01 << 27;
         
      // again, wait some time
      for( volatile int i = 0; i < 100'000; i++ ){}
      
   } 
}

