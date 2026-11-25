// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// EndianDataStandIn4c4: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// EndianDataStandIn4c4::Func004c45e0: GUESS(low); placeholder name
#pragma once

// The byte swap is the intrinsic the function compiles to, declared here for the unit.
extern "C" unsigned long _byteswap_ulong(unsigned long);


struct EndianDataStandIn4c4 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08[21][2];
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    void Func004c45e0();
};


inline void SwapEndianU(unsigned int& v)
{
    // One bswap instruction is what the target does for each field.
    v = _byteswap_ulong(v);
}
