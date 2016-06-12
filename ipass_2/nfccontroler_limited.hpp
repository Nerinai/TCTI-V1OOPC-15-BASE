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
/// This class contains the nfccontroler abstraction for the detecteion, selection,
/// communication and errorchecking when communicating with an NFC card.

class nfccontroler_limited
{
public:
/// Function checking the error and irq results after sending or recieving data.
///
/// This function inserts the status of the registers in a byte array that is
/// given to the function as a parameter.
///
/// The use function requires knowledge of how the chip returns these results.
	virtual void 	checkErroAndIrq 	(byte * result) = 0;

/// Function for using the trancieving data.
/// 
/// This function is used for sending data and commands to the card in the form of bytes.
/// It sends the data stored in an byte array.
/// After sending the data it inserts any recieved data in the data_out array.
/// It will also supply the ammount of bytes recieved unless a nullptr is given to data_out_lenght.
/// The crc and REQA booleans are used to trigger the aditional functionality of
/// Calculating and adding the crc and the use of a specialised bitframe for certain commands respectively.
/// It is reccomended to atleast have a basic understanding of the card-protocol and microcontroler in use when using this function.
	virtual bool	trancieveData		(const byte * data_in,
											const int data_in_lenght, 
											byte * data_out, 
											int * data_out_lenght, 
											bool crc = false, 
											bool REQA = false) = 0;
/// \cond INTERNAL

	virtual bool 	authentCard			(const byte * data_in, const int data_in_lenght) = 0;
	
/// \endcond


/// Function for detecting if a card is in the EM field.
///
/// This function constantly polls for a card in the EM field
/// When a card responds it inserts the response (Sak) in the cardtype byte array.
/// This response can be used to identify the tyep of card.
/// Before a card responds to this function it will not respond to any other command.
/// It is currently not supported to have multiple cards in the EM field at the same time.
/// Function will return true on successfull detection of a card.
	virtual bool	isCard 				(byte * cardtype) = 0;

/// Function for the selection of the card.
///
/// This function requests the UID (Unique Identifyer) from the card and then uses the UID to select the card.
/// It inserts the UID into the Cardserial array. 
/// When a card has been successfully selected its UID can be used to send other data and commands towwards the card.
/// This function returns true after the successfull selection of a card.
	virtual bool	selectCard			(byte * Cardserial) = 0;
	
/// Function for authenticating access to a sector.
///
/// This function grants access to the specified sector of the card.
/// The typekey parameter is used to specify which key is used for authentication.
/// The block_address parameter is used to select which sector is authenticated for.
/// The key parameter is used to provide they key in byte array form to the specified sector.
/// Any block in a sector may be targeted for authentication and will grant access to all blocks in that sector.
/// This function returns true after successfull authentication.
	virtual bool	authenticateSector	(byte typekey,
											byte * block_address,
											byte * key,
											byte * Cardserial) = 0;
/// Function for reading a block of data from the card.
///
/// This function reads data from a single block of data inside the card.
/// After reading the data it inserts this in the data_out array parameter.
/// It is required to authenticate for the sector that the block resides in before atempting to read.
/// Upon successfull reading of data this function returns true.
	virtual bool	readBlock			(byte block_address, byte * data_out) = 0;

/// Function for reading an entire sector of data from the card.
///
/// This function reads an entire sector of data.
/// After reading the data it inserts this in the sector_out 2d matrix parameter.
/// Authentication is built in for this function.
/// The typekey parameter is used to specify which key is used for authentication.
/// The first_block_in_sector parameter is used to select which sector is authenticated for.
/// The key parameter is used to provide they key in byte array form to the specified sector.
/// Upon successfull reading of the sector this function returns true.
	virtual bool 	readSector			(const int sectorsize, 
											byte (*sector_out)[16], 
											byte typekey, 
											byte * first_block_in_sector, 
											byte * key, 
											byte * Cardserial) = 0;
											
/// Function for writing a block of data to the card.
///
/// This function writes data to a single block of data inside the card.
/// The paramater data_in is used to provide the data to write in byte array form.
/// The data given to the function is appended with zeroes so a full block is always writen.
/// It is required to authenticate for the sector that the block resides in before atempting to write.
/// Upon successfull writing of data this function returns true.
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
/// Upon successfull writing of the sector this function returns true.
	virtual bool	writeSector			(const int sectorsize, 
											byte (*sector_in)[16], 
											byte typekey, 
											byte * first_block_in_sector, 
											byte * key, 
											byte * Cardserial) = 0;
/// \cond INTERNAL
	virtual int		calculateCRC		(const byte * data,
											const int length, 
											byte * result) = 0;
/// \endcond

};

#endif // NFCCONTROLER_LIMITED_HPP
