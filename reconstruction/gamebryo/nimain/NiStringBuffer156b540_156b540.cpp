// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x156b540 NiStringBuffer156b540::NiStringBuffer156b540
#include "NiStringBuffer156b540_156b540.h"

NiStringBuffer156b540::NiStringBuffer156b540(std::size_t size)
{
    data = AllocateStringBuffer(size);
    // NOTE: the original writes the terminator before checking the handle.
    data[0] = '\0';
    if (data) {
        std::size_t length = static_cast<std::size_t>(-1);
        do {
            ++length;
        } while (data[length] != '\0');
        reinterpret_cast<std::size_t*>(data)[-1] = length;
    }
}
