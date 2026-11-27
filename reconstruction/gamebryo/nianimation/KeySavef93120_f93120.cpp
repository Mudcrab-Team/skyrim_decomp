// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf93120 KeySavef93120::SaveToStream
#include "KeySavef93120_f93120.h"

void KeySavef93120::SaveToStream(KeyStreamf93120& stream, KeySavef93120* keys, std::uint32_t count)
{
    for (std::uint32_t index = 0; index < count; ++index) {
        SaveBinary(stream, &keys[index]);
    }
}
