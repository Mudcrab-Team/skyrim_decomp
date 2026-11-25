// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf8f550 KeySavef8f550::SaveToStream
#include "KeySavef8f550_f8f550.h"

void KeySavef8f550::SaveToStream(KeyStreamf8f550& stream, KeySavef8f550* keys, std::uint32_t count)
{
    for (std::uint32_t index = 0; index < count; ++index) {
        SaveBinary(stream, &keys[index]);
    }
}
