// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceEffect, ImageSpaceEffect::active, ImageSpaceEffect::unk09, ImageSpaceEffect::effects, ImageSpaceEffect::effectParams, ImageSpaceEffect::effectTextures, ImageSpaceEffect::effectInputs, ImageSpaceEffect::unk70, ImageSpaceEffect::unk88, ImageSpaceEffectParam, ImageSpaceTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's layout
// ImageSpaceEffectGetHit: CRASHLOGGER_PDB(59818@2026.10.24); name only
// ImageSpaceEffectGetHit::textures, ImageSpaceEffectGetHit::unk90: GUESS(low); offsets from the listing
// NiTArray, NiTPrimitiveArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the shape of the array and its set-at routine, written from the listing
// NiTArray::SetAt: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); the name only, the body is written from the listing
// FreeArrayStorage, NiTArray::data, NiTArray::maxSize, NiTArray::size, NiTArray::elementCount, NiTArray::growBy: GUESS(low); the storage callee at 0xeaca30 and member names
// Adapted bodies: none. The origin check reports NiTArray::~NiTArray as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niconsolerenderer/nivbset.cpp:447
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceTexture
{
public:
    ~ImageSpaceTexture();  // callee at 0x1554ed0, not compared here

    std::uint8_t unk00[0x20];
};

class ImageSpaceEffectParam
{
public:
    virtual ~ImageSpaceEffectParam();
};

// The array frees its storage through the callee at 0xeaca30.
void FreeArrayStorage(void* a_storage);

template <class T>
class NiTArray
{
public:
    NiTArray()
    {
        maxSize = 0;
        size = 0;
        elementCount = 0;
        growBy = 1;
        data = nullptr;
    }
    virtual ~NiTArray() { FreeArrayStorage(data); }

    void SetAt(std::uint32_t a_index, T a_element)
    {
        if (a_index >= size) {
            size = static_cast<std::uint16_t>(a_index + 1);
            if (a_element) {
                ++elementCount;
            }
        } else if (data[a_index]) {
            if (!a_element) {
                --elementCount;
            }
        } else if (a_element) {
            ++elementCount;
        }
        data[a_index] = a_element;
    }

    T* data;                     // 08
    std::uint16_t maxSize;       // 10
    std::uint16_t size;          // 12
    std::uint16_t elementCount;  // 14
    std::uint16_t growBy;        // 16
};

template <class T>
class NiTPrimitiveArray : public NiTArray<T>
{
};
static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18, "array size");

class ImageSpaceEffect
{
public:
    class EffectInput;

    ImageSpaceEffect();
    virtual ~ImageSpaceEffect();  // callee at 0x1553a30, not compared here

    bool active;                                             // 08
    bool unk09;                                              // 09
    NiTPrimitiveArray<ImageSpaceEffect*> effects;            // 10
    NiTPrimitiveArray<ImageSpaceEffectParam*> effectParams;  // 28
    NiTPrimitiveArray<ImageSpaceTexture*> effectTextures;    // 40
    NiTPrimitiveArray<EffectInput*> effectInputs;            // 58
    NiTPrimitiveArray<std::int32_t> unk70;                   // 70
    bool unk88;                                              // 88
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class ImageSpaceEffectGetHit : public ImageSpaceEffect
{
public:
    ~ImageSpaceEffectGetHit() override;  // compared: 0x1582a80

    std::uint8_t unk90[8];          // 90
    ImageSpaceTexture textures[3];  // 98
};
static_assert(sizeof(ImageSpaceEffectGetHit) == 0xF8, "ImageSpaceEffectGetHit size");
