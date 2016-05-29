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
	RC_522(hwlib::pin_out & IRQ, hwlib::pin_out & SDA, hwlib::pin_in_out & RESET, hwlib::spi_bus & spiBus):
	IRQ(IRQ),
	SDA(SDA),
	RESET(RESET),
	spiBus(spiBus)
	{}

#endif //RFID_RC522_H