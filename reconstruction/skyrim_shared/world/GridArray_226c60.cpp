// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of coordinate-ordered grid detachment.
// 0x226c60 GridArray::DetachAll
#include "GridArray_226c60.h"

void GridArray::DetachAll()
{
    for (std::uint32_t x = 0; x < length; ++x) {
        for (std::uint32_t y = 0; y < length; ++y) {
            Detach(x, y);
        }
    }
}
