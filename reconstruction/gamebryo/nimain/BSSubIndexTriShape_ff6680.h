// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSSubIndexTriShape, BSSubIndexTriShape::Functionff6680: GUESS(low)
// SubSegment, subSegments, flag170: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct SubSegment
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    uint32_t e;
};

class BSSubIndexTriShape
{
public:
    void Functionff6680(uint32_t a_index, uint32_t a_a, uint32_t a_b);

    unsigned char pad000[0x160];
    SubSegment* subSegments;
    unsigned char pad168[0x8];
    bool flag170;
};
