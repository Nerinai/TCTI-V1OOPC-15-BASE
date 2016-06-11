#ifndef NFCCONTROLER_LIMITED_HPP
#define NFCCONTROLER_LIMITED_HPP
#include "hwlib.hpp"

class nfccontroler_limited
{
public:

	virtual void 	checkErroAndIrq 	(byte * result) = 0;
	
	virtual bool	trancieve			(const byte * data_in,
											const int data_in_lenght, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool REQA = false) = 0;
											
	virtual bool 	authent				(const byte * data_in, const int data_in_lenght) = 0;
											
	virtual bool	iscard 				(byte * cardtype) = 0;
	virtual bool	select_card			(byte * Cardserial) = 0;
	virtual bool	authenticate_classic(byte typekey,
											byte * block_address,
											byte * key,
											byte * Cardserial) = 0;
											
	virtual bool	readblock			(byte block_address, byte * data_out) = 0;
	
	virtual bool 	readSector			(const int sectorsize, 
											byte (*sector_out)[16], 
											byte typekey, 
											byte * first_block_in_sector, 
											byte * key, 
											byte * Cardserial) = 0;
	
	virtual bool	writeBlock			(const byte block_address,
											const byte * data_in,
											const int lenght) = 0;
											
	virtual bool	writeSector			(const int sectorsize, 
											byte (*sector_in)[16], 
											byte typekey, 
											byte * first_block_in_sector, 
											byte * key, 
											byte * Cardserial) = 0;
											
	virtual int		calculateCRC		(const byte * data,
											const int length, 
											byte * result) = 0;

};

#endif // NFCCONTROLER_LIMITED_HPP
