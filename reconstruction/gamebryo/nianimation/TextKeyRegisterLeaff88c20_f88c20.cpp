// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf88c20 TextKeyRegisterLeaff88c20::RegisterStreamables
#include "TextKeyRegisterLeaff88c20_f88c20.h"

bool TextKeyRegisterLeaff88c20::RegisterStreamables(TextStreamf88c20& stream)
{
    if (!TextKeyBasef88c20::RegisterStreamables(stream)) {
        return false;
    }
    for (std::uint32_t index = 0; index < count; ++index) {
        keys[index].Register(stream);
    }
    return true;
}
