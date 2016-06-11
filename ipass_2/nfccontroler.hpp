#ifndef NFCCONTROLER_HPP
#define NFCCONTROLER_HPP
#include "hwlib.hpp"
#include "nfccontroler_limited.hpp"

class nfccontroler : public nfccontroler_limited
{
protected:
	
public:
	
	virtual byte	readRegister		(byte a ) = 0;
	virtual void	writeRegister		(byte a, byte value) = 0;
	virtual void	setRegisterMask		(byte a, byte value) = 0;
	virtual void	clearRegisterMask	(byte a, byte value) = 0;
	
	virtual byte	getAntennaGain		(void) = 0;
	virtual void	setAntennaGain		(byte value) = 0;
	virtual void	antennaOn			(void) = 0;
	virtual void	antennaOff			(void) = 0;
	
	virtual void 	checkErroAndIrq 	(byte * result) = 0;
	
	virtual int		readFIFO			(void) = 0;
	virtual int		readFIFO			(byte * output) = 0;
	virtual int		writeFIFO			(const byte value) = 0;
	virtual int		writeFIFO			(const int byte_amount, const byte * data) = 0;
	
	virtual void	selfTest			(void) = 0;
	virtual void	initChip			(void) = 0;
	
	virtual bool	trancieveData			(const byte * data_in,
											const int data_in_lenght, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool REQA = false) = 0;
											
	virtual bool 	authentCard			(const byte * data_in, const int data_in_lenght) = 0;
	
	virtual bool	communicateNFC		(const byte * data_in,
											const int data_in_lenght, 
											byte command, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool REQA = false) = 0;
											
	virtual bool	isCard 				(byte * cardtype) = 0;
	virtual bool	selectCard			(byte * Cardserial) = 0;
	virtual bool	authenticateCard	(byte typekey,
											byte * block_address,
											byte * key,
											byte * Cardserial) = 0;
											
	virtual bool	readBlock			(byte block_address, byte * data_out) = 0;
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

#endif // NFCCONTROLER_HPP
