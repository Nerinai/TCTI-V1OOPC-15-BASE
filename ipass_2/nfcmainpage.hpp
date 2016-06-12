// ==========================================================================
//
// File      : nfcmainpage.hpp
// Part of   : nfccontroler library for V1IPAS
// Copyright : David de Jong (c) 2016
// Contact   : marijn_david@hotmail.com
//
// Main page for doxygen. Is not included with the compilation.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
/// @file

/// nfccontroler class

/// \mainpage

/// \author David de Jong (marijn_david@hotmail.com)
/// \version 1.0 (last modified 2016-06-11)
/// \copyright Published under the boost licence. 

/// nfccontroler is a library for the use of controling NFC reader microcontrolers.
/// This library was made as part of the V1IPAS-TI course at the Hogeschool Utrecht.
/// This library is intended to be used with Hwlib ((c) Wouter van Ooien (wouter@voti.nl).
/// The language is C++ from the 2011 standard.
///
/// This library currently supports the follwing NFC microcontrolers:
/// 	- RFID - RC522
///
/// And the follwing card protocols:
///		- Mifare Classic. which uses parts of the (ISO/IEC 14443-3 Type A) standard.
///
///
/// The library is used by including either nfccontroler_all.hpp 
/// or, prefferably, by including the NFC chip and card protocol you want to use.
///
/// Naming conventtion:
///
/// - Functions that have 'register' as part of their name are used to
///	  manipulate the internal registers of the NFC microcontroler.
///   These functions are low level and ONLY ment to be used if the user has INTIMATE
///   KNOWLEDGE of the internal workings of the microcontroler in question.
///   These functions set, get or alter the varriables currently available in the register.
///   Using such a function twice in the same context will not alter the effect.
///   The only exception to this is the FIFO-buffer because this register is used to store data.
///
/// - Functions with more descriptive names such as 'antennaOn' or 'calcCRC'
///   are used to perform standard operations of the microcontroler.
///   Caution is advised since some if these functions require advanced knowledge
///   of the internal workings of the card protocol or microcontroler.
///
/// - Functions that contain the words 'block' or 'sector' as part of their name
///   are functions that deal with sending and recieving information to the card
///   in coherence with the used protocol.
///   These functions are the top level of the library and are intended for general use.
///
///
/// Usability:
///
/// - The top level of this library is ment to be usable and understandable by 
///   people with a basic understanding of C++ and the card protocol they are using.
///
/// - The low level functions are ment to be usable and understandable by people with
///   a more advanded understanding of the microcontrolers functionality.

/// \page todo TO do list
///
/// Future expansions:
/// - Cascade functionality for the anticollision loop (selectCard) to allow multiple cards in the EM field.
/// - Functionality to change the Securitybytes of a sector.
/// - Improved bitwraping functionality for the CommunicateNFC function.
/// - Variable lenght matrix suport for use with diferent card standards.
/// - Support for other mifare protocols.
/// - Support for non mifare protocols.
/// - Support for other NFC microcontrolers.
