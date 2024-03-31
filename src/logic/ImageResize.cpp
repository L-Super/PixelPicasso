/**
 * Created by LMR on 2024/3/30.
*/

#include "ImageResize.h"
#include "spdlog/spdlog.h"
#include <QImage>
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
    spdlog::info("input image path: {} scale: {}", imagePath, scale);
    if (!isSupportedFormat(imagePath)) {
        spdlog::error("unknown image type");
        return;
    }
    else {
        spdlog::info("support image type");
    }
    int iw{};
    int ih{};
    int channel{};
    // 加载图片获取宽、高、颜色通道信息
    unsigned char* inputData = stbi_load(imagePath.c_str(), &iw, &ih, &channel, 0);
    if (!inputData) {
        spdlog::error("read image was failed");
        return;
    }
    spdlog::info("input image width: {} height: {} channel: {}", iw, ih, channel);

    int width = iw * scale;
    int height = ih * scale;

    spdlog::info("output image width: {} height: {}", width, height);

    auto* outData = (unsigned char*) malloc(width * height * channel);

    // TODO:jpg格式崩溃
    // 改变图片尺寸
    stbir_resize(inputData, iw, ih, 0, outData, width, height, 0, STBIR_RGBA, STBIR_TYPE_UINT8, STBIR_EDGE_CLAMP,
                 STBIR_FILTER_DEFAULT);

    auto re = stbi_write_jpg("output.jpg", width, height, channel, outData, 100);
    spdlog::info("re:{]", re);
    if (re == 0) {
        spdlog::error("save image failed");
    }
    stbi_image_free(inputData);
    stbi_image_free(outData);

    //    QImage image(outData,width,height,QImage::Format::Format_RGBA64);
    // TODO: return data
}
bool ImageResize::isSupportedFormat(const std::string& imagePath)
{
    int width, height, channel;
    return stbi_info(imagePath.c_str(), &width, &height, &channel);
}
}// namespace pp
