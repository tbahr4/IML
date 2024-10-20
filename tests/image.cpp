/**************************************************
* File		:	test.cpp
* Project	:	Image Manipulation Library
* Date		:	10/19/2024
*
* Unit Tests for the Image class
*
**************************************************/

#include "gtest/gtest.h"
#include "image.h"
#include <filesystem>

TEST(png_test, Image)
{
	iml::Image* image;
	ASSERT_NO_THROW(image = new iml::Image("../testdata/image.png"));
}