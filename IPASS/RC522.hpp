/*#ifndef RC522_HPP
#define RC522_HPP

///@file

///+----------------------+
///| Author: David de Jong|
///| Date: 13.05.2016	  |
///| Version 0.1		  |
///+----------------------+

#include "hwlib.hpp"
#include "NfcControler.hpp"


class RC522 : public NfcControler
{
private:
	hwlib::pin_out & IRQ;
	hwlib::pin_out & SDA;
	hwlib::pin_in_out & RESET;
	hwlib::spi_bus & spiBus;
	byte versionreg = 0x37;
	byte result;
	int print;

public:
	RC522(hwlib::pin_out & IRQ, hwlib::pin_out & SDA, hwlib::pin_in_out & RESET, hwlib::spi_bus & spiBus):
	IRQ(IRQ),
	SDA(SDA),
	RESET(RESET),
	spiBus(spiBus),
	print(9999)
	{}
	
	void get_version(){
		//spiBus.write_and_read(SDA, 1, & versionreg, & result);
		hwlib::cout << print;
	}
};
#endif //RC522_HPP*/