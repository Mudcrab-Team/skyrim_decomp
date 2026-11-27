// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSGeometry, BSGeometry::Functionefcdc0, Sink, unk00, unk08, unk0C, unk10, unk18, sink: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Sink
{
public:
    typedef uint32_t (*Callback)(Sink* a_self, void* a_dest, uint32_t a_size, uint32_t* a_elem, uint32_t a_flag);

    uint64_t unk00;
    uint32_t unk08;
    uint32_t unk0C;
    Callback unk10;
    Callback unk18;
};

class BSGeometry
{
public:
    void Functionefcdc0(void* a_dest);

    uint8_t pad00[0x2a0];
    Sink*   sink;
};
