/**
 * Created by LMR on 2024/3/30.
*/

#include "ImageResize.h"
#include <QImage>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize2.h"

namespace pp {
ImageResize::ImageResize() {}

void ImageResize::resize(const std::string& imagePath, float scale)
{
    std::cout << "image path: " << imagePath << std::endl;
    int iw{};
    int ih{};
    int channel{};
    // 加载图片获取宽、高、颜色通道信息
    unsigned char* inputData = stbi_load(imagePath.c_str(), &iw, &ih, &channel, 0);
    if (!inputData) {
        std::cout << "read image was failed\n";
        return;
    }
    std::cout << "input data width: " << iw << " height: " << ih << " channel: " << channel << std::endl;
    int width = iw * scale;
    int height = ih * scale;
    std::cout << "output width: " << width << " height: " << height << std::endl;
    auto* outData = (unsigned char*) malloc(width * height * channel);

    // 改变图片尺寸
    stbir_resize(inputData, iw, ih, 0, outData, width, height, 0, STBIR_RGBA, STBIR_TYPE_UINT8, STBIR_EDGE_CLAMP,
                 STBIR_FILTER_DEFAULT);

    stbi_image_free(inputData);
    stbi_image_free(outData);
//    QImage image(outData,width,height,QImage::Format::Format_RGBA64);
    // TODO: return data
}
}// namespace pp
