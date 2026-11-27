// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectFullScreenBlur, ImageSpaceEffectFullScreenBlur::ctor: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and the texture array offset 0x40; bodies not compared here
// TextureArray, TextureArray::Function150b8f0, BlurEntry: STANDIN GUESS(low); the array callee at 0x150b8f0 takes the new capacity; BlurEntry is the 0x20-byte element with out-of-line constructor and destructor
// entries: GUESS(low); three elements at 0x90 from the vector constructor call in the listing
// kBlurA, kBlurB, kBlurC, g_blurA, g_blurB, g_blurC: GUESS(low); three float constants copied to three float globals; the values are not read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class TextureArray
{
public:
    void Function150b8f0(std::uint32_t a_capacity);  // callee at 0x150b8f0, not compared
    std::uint8_t unk00[0x18];
};

class BlurEntry
{
public:
    BlurEntry();   // callee at 0x43df10, not compared
    ~BlurEntry();  // callee at 0x1554ed0, not compared
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

extern float kBlurA;
extern float kBlurB;
extern float kBlurC;
extern float g_blurA;
extern float g_blurB;
extern float g_blurC;

class ImageSpaceEffectFullScreenBlur : public ImageSpaceEffect
{
public:
    ImageSpaceEffectFullScreenBlur();  // compared: 0x1583e00
    ~ImageSpaceEffectFullScreenBlur() override;

    BlurEntry entries[3];  // 90
};
static_assert(offsetof(ImageSpaceEffectFullScreenBlur, entries) == 0x90, "layout");
