// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShader, BSImagespaceShader::Function15415e0, Slot, unk00, unk08, unk10, unk48: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Slot
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
    virtual void unk48(int a_arg);
};

class BSImagespaceShader
{
public:
    void Function15415e0();

    Slot* unk00;
    Slot* unk08;
    Slot* unk10;
};
