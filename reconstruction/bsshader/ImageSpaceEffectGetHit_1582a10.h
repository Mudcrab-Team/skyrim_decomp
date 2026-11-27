// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectGetHit, ImageSpaceEffectGetHit::ctor: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and the texture array offset 0x40; bodies not compared here
// TextureArray, TextureArray::Function150b8f0, HitEntry: STANDIN GUESS(low); the array callee at 0x150b8f0 takes the new capacity; HitEntry is the 0x20-byte element with out-of-line constructor and destructor
// entries: GUESS(low); three elements at 0x98 from the vector constructor call in the listing
#pragma once

#include <cstdint>
#include <cstddef>

class TextureArray
{
public:
    void Function150b8f0(std::uint32_t a_capacity);  // callee at 0x150b8f0, not compared
    std::uint8_t unk00[0x18];
};

class HitEntry
{
public:
    HitEntry();   // callee at 0x43df10, not compared
    ~HitEntry();  // callee at 0x1554ed0, not compared
    std::uint8_t unk00[0x20];
};

class ImageSpaceEffect
{
public:
    ImageSpaceEffect();  // callee at 0x1553950, not compared here
    virtual ~ImageSpaceEffect();

    std::uint8_t unk08[0x38];
    TextureArray textures;  // 40
    std::uint8_t unk58[0x38];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class ImageSpaceEffectGetHit : public ImageSpaceEffect
{
public:
    ImageSpaceEffectGetHit();  // compared: 0x1582a10
    ~ImageSpaceEffectGetHit() override;

    std::uint8_t unk90[8];  // 90
    HitEntry entries[3];    // 98
};
static_assert(offsetof(ImageSpaceEffectGetHit, entries) == 0x98, "layout");
