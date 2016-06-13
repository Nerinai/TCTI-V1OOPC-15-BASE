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

/// nfccontroler library
///
/// \mainpage
///
/// \author David de Jong (marijn_david@hotmail.com)
/// \version 1.0 (last modified 2016-06-11)
/// \copyright Published under the boost licence (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).
///
/// This library is provided with NO WARANTY WHATSOEVER
///
/// nfccontroller is a library for the use of controlling NFC reader microcontrollers.
/// This library was made as part of the V1IPAS-TI course at the Hogeschool Utrecht.
/// This library is intended to be used with Hwlib ((c) Wouter van Ooien (wouter@voti.nl).
/// The language is C++ from the 2011 standard.
///
/// This library currently supports the following NFC microcontrollers:
/// 	- RFID - RC522
///
/// And the following card protocols:
///		- Mifare Classic. which uses parts of the (ISO/IEC 14443-3 Type A) standard.
///
///
/// The library is used by including either nfccontroler_all.hpp 
/// or, preferably, by including the NFC chip and card protocol you want to use.
///
/// Naming convention:
///
/// - Functions that have 'register' as part of their name are used to
///	  manipulate the internal registers of the NFC microcontroller.
///   These functions are low level and ONLY meant to be used if the user has INTIMATE
///   KNOWLEDGE of the internal workings of the microcontroller in question.
///   These functions set, get or alter the variables currently available in the register.
///   Using such a function twice in the same context will not alter the effect.
///   The only exception to this is the FIFO-buffer because this register is used to store data.
///
/// - Functions with more descriptive names such as 'antennaOn' or 'calcCRC'
///   are used to perform standard operations of the microcontroller.
///   Caution is advised since some if these functions require advanced knowledge
///   of the internal workings of the card protocol or microcontroller.
///
/// - Functions that contain the words 'block' or 'sector' as part of their name
///   are functions that deal with sending and receiving information to the card
///   in coherence with the used protocol.
///   These functions are the top level of the library and are intended for general use.
///
///
/// Usability:
///
/// - The top level of this library is meant to be usable and understandable by 
///   people with a basic understanding of C++ and the card protocol they are using.
///
/// - The low level functions are meant to be usable and understandable by people with
///   a more advanced understanding of the microcontrollers functionality.

/// \page todo To do list
///
/// Future expansions:
/// - Cascade functionality for the anti-collision loop (selectCard) to allow multiple cards in the EM field.
/// - Functionality to change the Security bytes of a sector.
/// - Improved CRC handling so CRC can be added even if the amount of bytes sent fills up the buffer.
/// - Improved bit wrapping functionality for the CommunicateNFC function.
/// - Variable length matrix support for use with different card standards.
/// - Support for other MIFARE protocols.
/// - Support for non MIFARE protocols.
/// - Support for other NFC microcontrollers.
