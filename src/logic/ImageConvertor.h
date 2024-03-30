/**
 * Created by LMR on 2024/2/18.
*/

#pragma once

#include <string>
namespace pp {

enum class ImageFormat { JPG, PNG, SVG, WEBP, HEIC, ICO };

class ImageConvertor {
public:
    ImageConvertor();
    ~ImageConvertor();

    void Convert(const std::string& imagePath, ImageFormat format);

private:
    ImageFormat ImageFormatAnalyze(const std::string& imagePath);
};
}// namespace pp
