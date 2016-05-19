#ifndef RFID_RC522_H
#define RFID_RC522_H

//personal note
// SDA = Grijs
// SCL = Oranje
// MOSI = Geel
// MISO = Bruin
// IRQ = paars
// GROUND = groen
// RESET = Blauw
// VCC = Rood

///@file

///+----------------------+
///| Author: David de Jong|
///| Date: 13.05.2016	  |
///| Version 0.1		  |
///+----------------------+

#include "hwlib.hpp"
#include "NfcControler.h"


class RC_522 : public NfcControler
{
	protected:
	hwlib::pin_out & IRQ;
	hwlib::pin_out & SDA;
	hwlib::pin_in_out & RESET;
	hwlib::spi_bus & spiBus;

public:
	/// constructor for default pin configuration for ease of use.
	/// sets the following pins.
	/// IRQ =  pin d9, SDA = pin d10, RESET = d11,
	/// SCL = pin scl, MOSI = pin mosi, MISO = pin miso.
	/// SCL, MISO and MOSI are then injected into the spiBus field.
	RC_522(hwlib::pin_out & IRQ, hwlib::pin_out & SDA, hwlib::pin_in_out & RESET, hwlib::spi_bus & spiBus)://hwlib::pin_out % IRQ, hwlib::pin_out % SDA, ,hwlib::spi_bus & spiBus):
	IRQ(IRQ),
	SDA(SDA),
	RESET(RESET),
	spiBus(spiBus)
	{}
	
	
	void blink() override
	{
		while(1)
		{
			RESET.set( 1 );
			hwlib::wait_ms( 200 );
			RESET.set( 0 );
			hwlib::wait_ms( 200 );
		}
	}
};

#endif //RFID_RC522_H