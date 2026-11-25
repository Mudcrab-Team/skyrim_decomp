// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ChannelState::ClearFloatKeys.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nieulerrotkey.cpp:22
// 0xf6e4c0 ChannelState::ClearFloatKeys
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nieulerrotkey.cpp:23
#include "ChannelState_f6e4c0.h"

void ChannelState::ClearFloatKeys()
{
    for (int i = 0; i < 3; ++i)
    {
        if (values[i])
            Data011f38a0[channelProperties[i + 3]](values[i]);
        values[i] = 0;
        channelProperties[i] = 0;
        channelProperties[i + 3] = 0;
    }
}
