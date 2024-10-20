#include "image.h"
#include <string>
#include <fstream>
#include <iostream>


iml::Image::Image(const std::string& imagePath) {
	std::ifstream file;
	file.open(imagePath, std::ios::binary);
	if (!file.is_open()) {
		throw std::exception("IML::Image::Image: Could not open file");
	}

	//! Determine file type
	std::string fileType = imagePath.substr(imagePath.find_last_of(".") + 1);
	iml::Image::Type type = iml::Image::Type::NONE;
	if (fileType == "png") {
		type = iml::Image::Type::PNG;
	}

	//! Process file contents into buffer
	bool success = processImageData(file, type);
	if (!success) {
		file.close();
		throw std::exception("IML::Image::Image: Image processing failed");
	}

	file.close();
}

//! Processes and stores image data into object buffers based
//! on the provided image type.
bool iml::Image::processImageData(std::ifstream& bitStream, iml::Image::Type imageType) {
	if (imageType == iml::Image::Type::NONE) {
		return false;
	}

	//! Process corresponding image type
	if (imageType == iml::Image::Type::PNG) {
		//! Read header
		iml::png::Header header;
		bitStream.read((char*)&header, sizeof(header));

		if (header.safetyBit != 0x89 || 
			(char)header.format[0] != 'P' || 
			(char)header.format[1] != 'N' ||
			(char)header.format[2] != 'G' ||
			header.crlf != 0x0D0A ||				// TODO: Swap endianness, do this by reading as char buffer, and swapping each piece of data, or create ifstream wrapper
			header.eof != 0x1A || 
			header.lf != 0x0A) 
		{ 
			std::cout << "IML::Image::processImageData: Encountered invalid file header" << std::endl;
			return false;
		}

		//! Read contents
		// TODO
	}

	return true;
}