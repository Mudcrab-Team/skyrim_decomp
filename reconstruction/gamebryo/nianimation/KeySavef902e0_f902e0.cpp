// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf902e0 KeySavef902e0::SaveToStream
#include "KeySavef902e0_f902e0.h"

void KeySavef902e0::SaveToStream(KeyStreamf902e0& stream, KeySavef902e0* keys, std::uint32_t count)
{
    for (std::uint32_t index = 0; index < count; ++index) {
        SaveBinary(stream, &keys[index]);
    }
}
