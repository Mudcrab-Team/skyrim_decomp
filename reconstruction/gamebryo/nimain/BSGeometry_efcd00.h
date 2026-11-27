// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSGeometry, BSGeometry::Functionefcd00, unk08, unk10, unk18: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSGeometry
{
public:
    typedef uint32_t (*Callback)(BSGeometry* a_self, void* a_dest, uint32_t a_size, uint32_t* a_elem, uint32_t a_flag);

    void Functionefcd00(void* a_dest, uint32_t a_count);

    uint64_t unk00;
    uint32_t unk08;
    uint32_t unk0C;
    Callback unk10;
    Callback unk18;
};
