/**************************************************
* File		:	image.h
* Project	:	Image Manipulation Library
* Date		:	10/18/2024
* 
* Defines an object for storing image data
*
**************************************************/
#pragma once

#include <vector>
#include <string>
#include "image_defs.h"


namespace iml {

	class Image {
	private:
		enum class Type {
			NONE = 0,
			PNG = 1
		};

		struct Pixel {
			uint8_t r;
			uint8_t g;
			uint8_t b;
			uint8_t a;
		};

		std::vector<std::vector<Pixel>> pixels;

	public:
		Image(const std::string& imagePath);

	private:
		bool processImageData(std::ifstream& bitStream, Type imageType);
	};

}
