// ==========================================================================
//
// File      : nfccontroler_limited.hpp
// Part of   : nfccontroler library for V1IPAS
// Copyright : David de Jong (c) 2016
// Contact   : marijn_david@hotmail.com
//
// Abstraction layer for functions on the Microcontroller side of the library.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
/// @file

#ifndef NFCCONTROLER_HPP
#define NFCCONTROLER_HPP
#include "hwlib.hpp"
#include "nfccontroler_all.hpp"

/// nfccontroler abstraction layer for functions on the microcontroller side of the library.
///
/// WARNING the use of most functions in this class requires INTIMATE KNOWLEDGE of the inner workings of the microcontroller
/// and its registers. 
/// Do NOT make use of these functions unless you confidently know what you are doing.
/// The functions in question will be marked with the warning INTIMATE KNOWLEDGE REQUIRED.
///
/// This class contains the nfccontroler abstraction for the reading and writing of microcontroller registers.
/// The setting and clearing of specific bits inside a register.
/// The core functionality of communication used by the microcontroller.
/// And convenience functions for controlling the antenna of the microcontroller.


class nfccontroler : public nfccontroler_limited
{
protected:
	
public:
/// Function for reading the current settings of a register.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function returns the current bits set in a register in the form of a single byte.
/// The parameter 'byte registerAddress' is used to supply the address of the register.
///
/// WARNING make sure you know if the register you are reading from preserves its data when read.
/// An example of this is the FIFO-buffer from the RC522 which deletes the byte read from the buffer afterwards.
/// To prevent data loss make sure the byte returned is stored somewhere if this situation occurs.
	virtual byte	readRegister		(byte registerAddress ) = 0;
	
/// Function for writing a single byte to a register.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function writes a single byte of data to the selected register.
/// The 'byte registerAddress' parameter is used to select the address of the register.
/// The 'byte value' parameter is used to provide the byte to be written.
///
/// WARNING this function sends the whole byte of data to be written to the register.
/// It can potentially overwrite previously set settings of that register.
	virtual void	writeRegister		(byte registerAddress, byte value) = 0;
	
/// Function for altering the settings of a register without overwriting all the bits stored in a register.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function sets the given bits in the bite provided. 
/// It does this WITHOUT altering the other bits in the register.
/// This means that al ZEROES in the byte will be ignored.
/// The 'byte registerAddress' parameter is used to select the address of the register.
/// The 'byte value' parameter is used to provide the bits to be changed in the register.
	virtual void	setRegisterMask		(byte registerAddress, byte value) = 0;

/// Function for altering the settings of a register without overwriting all the bits stored in a register.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function resets the given bits in the bite provided. 
/// It does this WITHOUT altering the other bits in the register.
/// This means that al ZEROES in the byte will be ignored.
/// The 'byte registerAddress' parameter is used to select the address of the register.
/// The 'byte value' parameter is used to provide the bits to be changed in the register.
	virtual void	clearRegisterMask	(byte registerAddress, byte value) = 0;

/// Function for reading the antennas current Gain setting.
///
/// This function returns a byte value that represents the current gain setting of the microcontrollers antenna.
/// The meaning of this byte usually represented in the microcontrollers appropriate documentation.
/// Using this function requires some knowledge of the microcontroller in question, caution is advised.
	virtual byte	getAntennaGain		(void) = 0;
	
/// Function for setting the antennas gain.
///
/// This function sets the gain level of the antenna by sending a byte to the antennas register.
/// The meaning of the bits contained in the byte is usually represented in the microcontrollers appropriate documentation.
/// Using this function requires some knowledge of the microcontroller in question, caution is advised.
	virtual void	setAntennaGain		(byte value) = 0;

/// Function for turning the mircocontrollers antenna on.
///
/// Turns the antenna on.
	virtual void	antennaOn			(void) = 0;

/// Function for turning the microcontrollers antena off
///
/// Turns the antenna off.
	virtual void	antennaOff			(void) = 0;
	
/// \cond PLACEHOLDER
	virtual void 	checkErroAndIrq 	(byte * result) = 0;
/// \endcond

/// A function that returns a single byte from the FIFO-buffer.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function reads a single byte from the FIFO-buffer and returns this.
/// WARNING make sure you know if the FIFO-buffer of your microcontroller preserves its data when read.
/// An example of this is the FIFO-buffer from the RC522 which deletes the byte read from the buffer afterwards.
/// To prevent data loss make sure the byte returned is stored somewhere if this situation occurs.
	virtual byte	readFIFO			(void) = 0;

/// Function for reading data currently stored in the FIFO-buffer.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function reads all data currently stored in the FIFO-buffer.
/// It inserts this data into the 'output' parameter in array from.
/// The integer value returned is the amount of bytes about to be read from the buffer
/// WARNING make sure you know if the FIFO-buffer of your microcontroller preserves its data when read.
/// An example of this is the FIFO-buffer from the RC522 which deletes the byte read from the buffer afterwards.
/// To prevent data loss make sure the data is stored somewhere if this situation occurs.
/// It is important to know the maximum amount of data the buffer can hold so you can provide appropriate storage.
	virtual int		readFIFO			(byte * output) = 0;

/// A function that writes a single byte to the FIFO-buffer.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function writes a single byte to the FIFO-buffer.
/// It will return false if the FIFO-buffer is full. 
/// The parameter 'value' is used to provide the byte of data that needs to be written to the FIFO-buffer.
/// It is recommended that you know the size of your microcontroller’s FIFO-buffer to prevent data loss.
	virtual bool	writeFIFO			(const byte value) = 0;

/// A function that writes data to the FIFO-buffer.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function writes the data provided byte to the FIFO-buffer.
/// It will return false if the FIFO-buffer is full or if you provide so much data that the buffer will overflow. 
/// The 'byte_amount' parameter is used to provide the amount of data about to be sent to the FIFO-buffer.
/// the 'data' parameter is used to provide the actual data to be written in array form.
/// It is recommended that you know the size of your microcontroller’s FIFO-buffer to prevent data loss.
	virtual bool	writeFIFO			(const int byte_amount, const byte * data) = 0;

/// A Function that runs the self test function of the microcontroller in question.
///
/// The results of the self test are printed to the terminal and can be compared to the expected results usually defined
/// in the microcontroller’s documentation.
	virtual void	selfTest			(void) = 0;

/// A Function that readies the microcontroller for sending and receiving data.
///
/// This function initializes the basic functions of the chip and configures the needed registers to start sending and receiving data.
/// It also performs a soft reset to make sure the initialization always starts off with the same configuration.
/// The function also turns the antenna on.
	virtual void	initChip			(void) = 0;
/// \cond PLACEHOLDER
	virtual bool	trancieveData			(const byte * data_in,
											const int data_in_lenght, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool Bitwraping = false) = 0;
											
	virtual bool 	authentCard			(const byte * data_in, const int data_in_lenght) = 0;
/// \endcond

/// A function that provides the implementation of sending and receiving data.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function provides the core functionality for sending and receiving data.
/// The parameter 'data_in' provides the data that is to be sent in array format.
/// In combination with the 'data_in_lenght' parameter to inform the function the amount of data to be sent.
/// It is important to keep in mind the size of the buffer that transmits the data in order to prevent this from overflowing.
/// When data is received the data itself is inserted into the 'data_out' parameter in array form.
/// The amount of bytes received is inserted into the 'data_out_lenght' parameter.
///
/// The Boolean parameter 'crc' tells the function to or not to calculate the CRC for the data and add it to the to be sent data.
/// Keep in mind that the CRC result itself takes up some space in the buffer.
///
/// The Boolean parameter 'Bitwraping' tells the function to or not to use a specified bit-frame for sending the data.
/// An example of this is that the 'MIFARE Classic' standard of cards only responds to initial contact when the request command
/// is sent in a seven-bit frame.
///
/// FINAL WARNING this is a complicated function that requires knowledge of both the microcontroller and the card protocol being used. 
/// It is recommended that the user first reads the appropriate documentation of both the microcontroller and the protocol in use respectively.
/// USE WITH CAUTION
	virtual bool	communicateNFC		(const byte * data_in,
											const int data_in_lenght, 
											byte command, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool Bitwraping = false) = 0;
/// \cond PLACEHOLDER
	virtual bool	isCard 				(byte * cardtype) = 0;
	virtual bool	selectCard			(byte * Cardserial) = 0;
	virtual bool	authenticateSector	(byte typekey,
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
/// \endcond

/// Function that calculates the CRC for the given data.
///
/// WARNING INTIMATE KNOWLEDGE REQUIRED
///
/// This function takes data in array form into the parameter 'data'
/// Together with the integer 'length' which provides the amount of data
/// it calculates the result and inserts it into the parameter 'result' in array format.
	virtual bool	calculateCRC		(const byte * data,
											const int length, 
											byte * result) = 0;
};

#endif // NFCCONTROLER_HPP
