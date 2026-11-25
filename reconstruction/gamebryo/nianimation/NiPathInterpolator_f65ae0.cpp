// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf65ae0 NiPathInterpolator::Functionf65ae0
// Adapted bodies: none
#include "NiPathInterpolator_f65ae0.h"

SampleOut* NiPathInterpolator::Functionf65ae0(SampleOut* a_out, uint32_t a_first, uint32_t a_second, float a_t)
{
    int32_t type;
    uint8_t stride;
    unsigned char* data = nullptr;
    if (unk28) {
        type = unk28->type;
        stride = unk28->stride;
        data = unk28->data;
    } else {
        type = 0;
        stride = 0;
    }
    SampleFn sample = s_sampleTable[type];
    a_out->unk00 = nullptr;
    a_out->unk08 = 0;
    sample(a_t, data + stride * a_first, data + stride * a_second, a_out);
    return a_out;
}
