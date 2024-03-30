/**
 * Created by LMR on 2024/2/18.
*/

#include "ImageConvertor.h"

namespace pp {

ImageConvertor::ImageConvertor() {}
ImageConvertor::~ImageConvertor() {}

void ImageConvertor::Convert(const std::string& imagePath, ImageFormat format) {

}

ImageFormat ImageConvertor::ImageFormatAnalyze(const std::string& imagePath)
{
    return ImageFormat::WEBP;
}

}// namespace pp