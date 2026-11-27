// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectOption, ImageSpaceEffect: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and an out-of-line destructor, the callee at 0x1553a30, which the target calls
// The destructor is implicit on purpose: a declared empty destructor adds a store of the derived vtable pointer that the target lacks.
// OptionData, OptionData::buffer, FreeBuffer: STANDIN GUESS(low); a member with its own vtable at 0x90 whose destructor releases the pointer at 0x98 through the callee at 0xeaca30
#pragma once

#include <cstdint>
#include <cstddef>

void FreeBuffer(void* a_buffer);  // callee at 0xeaca30, not compared here

class ImageSpaceEffect
{
public:
    ImageSpaceEffect();
    virtual ~ImageSpaceEffect();
    std::uint8_t unk08[0x88];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class OptionData
{
public:
    OptionData() : buffer(nullptr), unk10(0) {}
    virtual ~OptionData() { FreeBuffer(buffer); }

    void* buffer;         // 08
    std::uint64_t unk10;  // 10
};
static_assert(sizeof(OptionData) == 0x18, "OptionData size");

class ImageSpaceEffectOption : public ImageSpaceEffect
{
public:
    ImageSpaceEffectOption();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x1552080

    OptionData data;  // 90
};
static_assert(sizeof(ImageSpaceEffectOption) == 0xa8, "ImageSpaceEffectOption size");
