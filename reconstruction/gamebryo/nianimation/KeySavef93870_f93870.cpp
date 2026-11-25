// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf93870 KeySavef93870::SaveToStream
#include "KeySavef93870_f93870.h"

void KeySavef93870::SaveToStream(KeyStreamf93870& stream, KeySavef93870* keys, std::uint32_t count)
{
    for (std::uint32_t index = 0; index < count; ++index) {
        SaveBinary(stream, &keys[index]);
    }
}
