// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf90f50 KeySavef90f50::SaveToStream
#include "KeySavef90f50_f90f50.h"

void KeySavef90f50::SaveToStream(KeyStreamf90f50& stream, KeySavef90f50* keys, std::uint32_t count)
{
    for (std::uint32_t index = 0; index < count; ++index) {
        SaveBinary(stream, &keys[index]);
    }
}
