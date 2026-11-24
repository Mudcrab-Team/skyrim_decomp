// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiPathInterpolator, NiPathInterpolator::Functionf65ae0: GUESS(low)
// SampleArray, SampleOut, SampleFn, s_sampleTable, unk28, type, stride, data: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct SampleOut
{
    void* unk00;
    uint32_t unk08;
};

struct SampleArray
{
    unsigned char pad00[0x18];
    unsigned char* data;
    int32_t type;
    uint8_t stride;
};

typedef void (*SampleFn)(float a_t, const void* a_first, const void* a_second, SampleOut* a_out);

class NiPathInterpolator
{
public:
    SampleOut* Functionf65ae0(SampleOut* a_out, uint32_t a_first, uint32_t a_second, float a_t);

    unsigned char pad000[0x28];
    SampleArray* unk28;

    static SampleFn s_sampleTable[];
};
