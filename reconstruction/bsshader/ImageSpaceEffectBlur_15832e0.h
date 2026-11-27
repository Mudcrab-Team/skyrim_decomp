// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectBlur, ImageSpaceEffectBlur::ctor: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and the texture array offset 0x40; bodies not compared here
// TextureArray, TextureArray::Function150b8f0: STANDIN GUESS(low); the callee at 0x150b8f0 takes the new capacity
// unk90, unk94, unk95: GUESS(low); offsets from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class TextureArray
{
public:
    void Function150b8f0(std::uint32_t a_capacity);  // callee at 0x150b8f0, not compared
    std::uint8_t unk00[0x18];
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

class ImageSpaceEffectBlur : public ImageSpaceEffect
{
public:
    ImageSpaceEffectBlur();  // compared: 0x15832e0
    ~ImageSpaceEffectBlur() override;

    std::int32_t unk90;  // 90
    bool unk94;          // 94
    bool unk95;          // 95
};
static_assert(offsetof(ImageSpaceEffectBlur, unk95) == 0x95, "layout");
