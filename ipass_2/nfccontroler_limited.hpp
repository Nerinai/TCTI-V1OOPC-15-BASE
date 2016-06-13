// ==========================================================================
//
// File      : nfccontroler_limited.hpp
// Part of   : nfccontroler library for V1IPAS
// Copyright : David de Jong (c) 2016
// Contact   : marijn_david@hotmail.com
//
// Abstraction layer for functions on the Card protocol side of the library.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
/// @file

#ifndef NFCCONTROLER_LIMITED_HPP
#define NFCCONTROLER_LIMITED_HPP
#include "hwlib.hpp"

/// nfccontroler abstraction layer for functions on the card protocol side of the library.
///
/// This class contains the nfccontroler abstraction for the detection, selection,
/// communication and error checking when communicating with an NFC card.

class nfccontroler_limited
{
public:
/// Function checking the error and IRQ results after sending or receiving data.
///
/// This function inserts the status of the registers in a byte array that is
/// given to the function as a parameter.
///
/// The use function requires knowledge of how the chip returns these results.
	virtual void 	checkErroAndIrq 	(byte * result) = 0;

/// Function for using the simultaneous sending and receiving of data.
/// 
/// This function is used for sending data and commands to the card in the form of bytes.
/// It sends the data stored in a byte array.
/// After sending the data it inserts any received data in the data_out array.
/// It will also supply the amount of bytes received unless a nullptr is given to data_out_lenght.
/// The crc and Bitwraping Booleans are used to trigger the additional functionality of
/// Calculating and adding the crc and the use of a specialised bit frame for certain commands respectively.
/// It is recommended to at least have a basic understanding of the card-protocol and microcontroller in use when using this function.
	virtual bool	trancieveData		(const byte * data_in,
											const int data_in_lenght, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool Bitwraping = false) = 0;
/// \cond INTERNAL

	virtual bool 	authentCard			(const byte * data_in, const int data_in_lenght) = 0;
	
/// \endcond


/// Function for detecting if a card is in the EM field.
///
/// This function constantly polls for a card in the EM field
/// When a card responds it inserts the response (Sak) in the cardtype byte array.
/// This response can be used to identify the type of card.
/// Before a card responds to this function it will not respond to any other command.
/// It is currently not supported to have multiple cards in the EM field at the same time.
/// Function will return true on successful detection of a card.
	virtual bool	isCard 				(byte * cardtype) = 0;

/// Function for the selection of the card.
///
/// This function requests the UID (Unique Identifier) from the card and then uses the UID to select the card.
/// It inserts the UID into the Cardserial array. 
/// When a card has been successfully selected its UID can be used to send other data and commands towards the card.
/// This function returns true after the successful selection of a card.
	virtual bool	selectCard			(byte * Cardserial) = 0;
	
/// Function for authenticating access to a sector.
///
/// This function grants access to the specified sector of the card.
/// The typekey parameter is used to specify which key is used for authentication.
/// The block_address parameter is used to select which sector is authenticated for.
/// The key parameter is used to provide they key in byte array form to the specified sector.
/// Any block in a sector may be targeted for authentication and will grant access to all blocks in that sector.
/// This function returns true after successful authentication.
	virtual bool	authenticateSector	(byte typekey,
											byte * block_address,
											byte * key,
											byte * Cardserial) = 0;
/// Function for reading a block of data from the card.
///
/// This function reads data from a single block of data inside the card.
/// After reading the data it inserts this in the data_out array parameter.
/// It is required to authenticate for the sector that the block resides in before attempting to read.
/// Upon successful reading of data this function returns true.
	virtual bool	readBlock			(byte block_address, byte * data_out) = 0;

/// Function for reading an entire sector of data from the card.
///
/// This function reads an entire sector of data.
/// After reading the data it inserts this in the sector_out 2d matrix parameter.
/// Authentication is built in for this function.
/// The typekey parameter is used to specify which key is used for authentication.
/// The first_block_in_sector parameter is used to select which sector is authenticated for.
/// The key parameter is used to provide they key in byte array form to the specified sector.
/// Upon successful reading of the sector this function returns true.
	virtual bool 	readSector			(const int sectorsize, 
											byte (*sector_out)[16], 
											byte typekey, 
											byte * first_block_in_sector, 
											byte * key, 
											byte * Cardserial) = 0;
											
/// Function for writing a block of data to the card.
///
/// This function writes data to a single block of data inside the card.
/// The parameter data_in is used to provide the data to write in byte array form.
/// The data given to the function is appended with zeroes so a full block is always written.
/// It is required to authenticate for the sector that the block resides in before attempting to write.
/// Upon successful writing of data this function returns true.
	virtual bool	writeBlock			(const byte block_address,
											const byte * data_in,
											const int lenght) = 0;
											
/// Function for writing an entire sector of data to the card.
///
/// This function writes an entire sector of data.
/// The sector_in parameter is used to provide the data to be written in 2d matrix form.
/// Authentication is built in for this function.
/// The typekey parameter is used to specify which key is used for authentication.
/// The first_block_in_sector parameter is used to select which sector is authenticated for.
/// The key parameter is used to provide they key in byte array form to the specified sector.
/// Upon successful writing of the sector this function returns true.
	virtual bool	writeSector			(const int sectorsize, 
											byte (*sector_in)[16], 
											byte typekey, 
											byte * first_block_in_sector, 
											byte * key, 
											byte * Cardserial) = 0;
/// \cond INTERNAL
	virtual int	calculateCRC		(const byte * data,
											const int length, 
											byte * result) = 0;
/// \endcond

};

#endif // NFCCONTROLER_LIMITED_HPP
