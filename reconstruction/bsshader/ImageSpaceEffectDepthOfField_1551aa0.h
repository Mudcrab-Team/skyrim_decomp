// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers, sibling names).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTArray::SetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nioldscreenspace.cpp:1754
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespacemanager.cpp:208
// ImageSpaceEffectDepthOfField, ImageSpaceEffectDepthOfField::ReturnTextures, ImageSpaceEffect, ImageSpaceEffect::effectTextures, ImageSpaceTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTArray, NiTPrimitiveArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTArray::SetAt: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); name only
// Function15550d0, Unk_01..Unk_04, data, maxSize, size, elementCount, growBy, unk08, unk58: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceTexture
{
public:
    void Function15550d0();  // callee at 0x15550d0, not compared
};

template <class T>
class NiTArray
{
public:
    virtual ~NiTArray();

    void SetAt(std::uint32_t a_index, T a_element)
    {
        if (a_index >= size) {
            size = static_cast<std::uint16_t>(a_index + 1);
            if (a_element) {
                ++elementCount;
            }
        } else if (a_element) {
            if (!data[a_index]) {
                ++elementCount;
            }
        } else if (data[a_index]) {
            --elementCount;
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
static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18, "NiTPrimitiveArray size");

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void ReturnTextures();

    std::uint8_t unk08[0x38];                              // 08
    NiTPrimitiveArray<ImageSpaceTexture*> effectTextures;  // 40
    std::uint8_t unk58[0x38];                              // 58
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class ImageSpaceEffectDepthOfField : public ImageSpaceEffect
{
public:
    void ReturnTextures() override;  // compared: 0x1551aa0
};
