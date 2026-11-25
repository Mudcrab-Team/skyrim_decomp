// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf923f0 KeySavef923f0::SaveToStream
#include "KeySavef923f0_f923f0.h"

void KeySavef923f0::SaveToStream(KeyStreamf923f0& stream, KeySavef923f0* keys, std::uint32_t count)
{
    for (std::uint32_t index = 0; index < count; ++index) {
        SaveBinary(stream, &keys[index]);
    }
}
