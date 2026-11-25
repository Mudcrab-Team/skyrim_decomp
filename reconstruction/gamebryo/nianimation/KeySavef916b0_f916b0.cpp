// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf916b0 KeySavef916b0::SaveToStream
#include "KeySavef916b0_f916b0.h"

void KeySavef916b0::SaveToStream(KeyStreamf916b0& stream, KeySavef916b0* keys, std::uint32_t count)
{
    for (std::uint32_t index = 0; index < count; ++index) {
        SaveBinary(stream, &keys[index]);
    }
}
