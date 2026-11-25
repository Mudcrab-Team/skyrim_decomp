// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSTweenerModifier, ResetFromSource, Block48, Source, block, blendC0, blend80, pad00, pad88, pad94: GUESS(low); stand-in class view, members named by offset only
#pragma once
#include <cstdint>
#include <intrin.h>

struct Block48
{
    __m128 rows[3];
};

struct Source
{
    std::uint8_t pad00[0x88];  // 00
    const Block48* block;      // 88
};

class BSTweenerModifier
{
public:
    void ResetFromSource(Source* const* a_source);  // compared: 0xbbc110

    std::uint8_t pad00[0x80];  // 00
    float blend80;             // 80
    std::uint8_t pad84[0xC];   // 84
    Block48 block90;           // 90
    float blendC0;             // C0
};
