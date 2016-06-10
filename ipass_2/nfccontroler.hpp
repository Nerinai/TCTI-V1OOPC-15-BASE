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
	virtual void	init_chip			(void) = 0;
	
	virtual bool	trancieve			(const byte * data_in,
											const int data_in_lenght, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool REQA = false) = 0;
											
	virtual bool 	authent				(const byte * data_in, const int data_in_lenght) = 0;
	
	virtual bool	communicate			(const byte * data_in,
											const int data_in_lenght, 
											byte command, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool REQA = false) = 0;
											
	virtual bool	iscard 				(byte * cardtype) = 0;
	virtual bool	select_card			(byte * Cardserial) = 0;
	virtual bool	authenticate_classic(byte typekey,
											byte * block_address,
											byte * key,
											byte * Cardserial) = 0;
											
	virtual bool	readblock			(byte block_address, byte * data_out) = 0;
	virtual bool	writeBlock			(const byte block_address,
											const byte * data_in,
											const int lenght) = 0;
											
	virtual int		calculateCRC		(const byte * data,
											const int length, 
											byte * result) = 0;
};

#endif // NFCCONTROLER_HPP
