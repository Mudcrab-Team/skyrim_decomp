// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1e5f10 (skyrim_shared/actors/Character_1e5f10): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Function1e5f90, Owner1e5f90: GUESS(low) STANDIN
// flags10: GUESS(low) STANDIN
#pragma once
#include "Character_1e5f10.h"

class Owner1e5f90
{
public:
    virtual void unk00();
    virtual void unk08();
    virtual void unk10();
    virtual void unk18();
    virtual void unk20();
    virtual void unk28();
    virtual void unk30();
    virtual void unk38();
    virtual void unk40();
    virtual void unk48();
    virtual void unk50(std::uint32_t a_arg);

    void Function1e5f90(bool a_set);

    std::uint64_t pad08;
    std::uint32_t flags10;
};

