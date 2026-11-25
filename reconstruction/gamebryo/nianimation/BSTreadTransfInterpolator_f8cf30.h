// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSTreadTransfInterpolator, NiInterpolator: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); class names only
// RefObj, refCount: GUESS(low)
// unk18, unk20, unk24, unk28, unk2C, unk30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class RefObj
{
public:
    virtual ~RefObj();

    volatile long refCount;
};

class NiInterpolator
{
public:
    NiInterpolator();
    virtual ~NiInterpolator();

    unsigned char pad08[0x10];
};

class BSTreadTransfInterpolator : public NiInterpolator
{
public:
    BSTreadTransfInterpolator(uint32_t a_value, void* a_data, RefObj* a_ref);

    void* unk18;
    uint32_t unk20;
    uint32_t unk24;
    uint32_t unk28;
    uint32_t unk2C;
    RefObj* unk30;
};
