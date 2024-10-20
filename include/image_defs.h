/**************************************************
* File		:	image_defs.h
* Project	:	Image Manipulation Library
* Date		:	10/19/2024
*
* Defines headers and potential contents of each 
* supported image type
* 
* Sources:
* - PNG: https://en.wikipedia.org/wiki/PNG
*
**************************************************/
#pragma once

#include <cstdint>
#include <vector>


namespace iml {
#pragma pack(push, 1)

	//! PNG
	//! 
	namespace png {
		struct Header {
			uint8_t safetyBit;		// 0x89 (The 'safety' byte that helps distinguish the file format)
			uint8_t format[3];		// 0x50 0x4E 0x47 ('PNG')
			uint16_t crlf;			// 0x0D 0x0A (CRLF)
			uint8_t eof;			// 0x1A (EOF marker)
			uint8_t lf;				// 0x0A (LF)
		};

		struct Chunk {
			uint32_t length;	// Size of chunk data
			uint32_t type;		// Type of chunk
			std::vector<uint8_t> data;	// Chunk data
			uint32_t crc;		// cyclic redundancy code/checksum
		};

	} // PNG

#pragma pack(pop)
}