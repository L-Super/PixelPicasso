/**
 * Created by LMR on 2024/3/30.
*/

#pragma once

#include <string>
namespace pp {
class ImageResize {
public:
    explicit ImageResize();
    ~ImageResize() = default;

    /**
     * resize image
     * @param imagePath input image path
     * @param scale scale ratio
     */
    void resize(const std::string& imagePath, float scale);

private:
};
}// namespace pp
