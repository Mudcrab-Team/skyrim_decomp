// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// ImageSpaceEffectOption::vfunc_1: CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceEffectOption, ImageSpaceEffect, NiTPrimitiveArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffectTexture, TextureBindingPair, Function1555120, VFunc01..VFunc09, SetAt, data, capacity, size, activeCount, growthSize, textures, effects, effectCount, effectParams, bindings, baseTexIndices, enabledFlags, texIndex, arg, unk08, unk20, unk24, unk38, unk50, unk68, unk80: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectTexture
{
public:
    void Function1555120(std::uint32_t a_arg);  // callee at 0x1555120, not compared
};

template <class T>
class NiTPrimitiveArray
{
public:
    virtual ~NiTPrimitiveArray();

    void SetAt(std::uint32_t a_index, T a_element)
    {
        if (a_index >= size) {
            size = static_cast<std::uint16_t>(a_index + 1);
            if (a_element) {
                ++activeCount;
            }
        } else {
            T old = data[a_index];
            if (a_element) {
                if (!old) {
                    ++activeCount;
                }
            } else if (old) {
                --activeCount;
            }
        }
        data[a_index] = a_element;
    }

    T* data;                    // 08
    std::uint16_t capacity;     // 10
    std::uint16_t size;         // 12
    std::uint16_t activeCount;  // 14
    std::uint16_t growthSize;   // 16
};
static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18, "NiTPrimitiveArray size");

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void VFunc01(void* a_arg1, void* a_param);  // +0x08

    std::uint8_t unk08[0x38];
    NiTPrimitiveArray<ImageSpaceEffectTexture*> textures;  // 40
};
static_assert(offsetof(ImageSpaceEffect, textures) == 0x40, "textures offset");

struct TextureBindingPair
{
    std::int32_t texIndex;  // 00
    std::uint32_t arg;      // 04
};

class ImageSpaceEffectOption
{
public:
    virtual ~ImageSpaceEffectOption();
    virtual void vfunc_1(void* a_arg1, void* a_arg2);  // compared: 0x1554740 (+0x08)
    virtual void VFunc02();
    virtual void VFunc03();
    virtual void VFunc04(void* a_arg2);                // +0x20
    virtual void VFunc05();                            // +0x28
    virtual void VFunc06();                            // +0x30
    virtual void VFunc07(void* a_arg2);                // +0x38
    virtual void VFunc08(void* a_param);               // +0x40
    virtual void VFunc09(void* a_param);               // +0x48

    std::uint8_t unk08[0x10];                  // 08
    ImageSpaceEffect** effects;                // 18
    std::uint16_t unk20;                       // 20
    std::uint16_t effectCount;                 // 22
    std::uint8_t unk24[0x0C];                  // 24
    void** effectParams;                       // 30
    std::uint8_t unk38[0x10];                  // 38
    ImageSpaceEffectTexture** textures;        // 48
    std::uint8_t unk50[0x10];                  // 50
    TextureBindingPair** bindings;             // 60
    std::uint8_t unk68[0x10];                  // 68
    std::uint32_t* baseTexIndices;             // 78
    std::uint8_t unk80[0x18];                  // 80
    std::uint8_t* enabledFlags;                // 98
};
static_assert(offsetof(ImageSpaceEffectOption, enabledFlags) == 0x98, "enabledFlags offset");
