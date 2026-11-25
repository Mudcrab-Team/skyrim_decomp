// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ChannelState: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// ChannelState::ClearFloatKeys: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
#pragma once

extern unsigned char Data011f3758[];
class ChannelState
{
  public:
    void ClearFloatKeys();
    int unk00, unk04, unk08, unk0c, unk10;
    int channelProperties[6];

    unsigned char encoded[3];
    void* values[3];
    int unk3c, unk40, unk44;
    void SetChannelValues(void* value0, int present0, unsigned type0, void* value1, int present1, unsigned type1,
                          void* value2, int present2, unsigned type2);
};
extern void(* Data011f38a0[])(void*);
