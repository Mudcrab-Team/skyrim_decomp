// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// ImageSpaceEffectGetHit, ImageSpaceEffectGetHit::BorrowTextures: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTPrimitiveArray, ImageSpaceEffectParam: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffect::effectTextures: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared here on ImageSpaceEffectGetHit
// ImageSpaceEffectTexture, Function1554f40, SetAt, data, capacity, emptySlot, size, growthSize, tex98, texB8, texD8, unk00, unk08, unk58: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectParam;

struct ImageSpaceEffectTexture
{
    void Function1554f40(std::int32_t a_type);  // callee at 0x1554f40, not compared

    std::uint8_t unk00[0x20];
};
static_assert(sizeof(ImageSpaceEffectTexture) == 0x20, "ImageSpaceEffectTexture size");

template <class T>
class NiTPrimitiveArray
{
public:
    virtual ~NiTPrimitiveArray();

    void SetAt(std::uint32_t a_index, const T& a_element)
    {
        if (a_index >= emptySlot) {
            emptySlot = static_cast<std::uint16_t>(a_index + 1);
            if (a_element) {
                ++size;
            }
        } else {
            T old = data[a_index];
            if (a_element) {
                if (!old) {
                    ++size;
                }
            } else if (old) {
                --size;
            }
        }
        data[a_index] = a_element;
    }

    T* data;                   // 08
    std::uint16_t capacity;    // 10
    std::uint16_t emptySlot;   // 12
    std::uint16_t size;        // 14
    std::uint16_t growthSize;  // 16
};

class ImageSpaceEffectGetHit
{
public:
    virtual ~ImageSpaceEffectGetHit();
    void BorrowTextures(ImageSpaceEffectParam* a_param);  // compared: 0x1582fc0

    std::uint8_t unk08[0x38];                                   // 08
    NiTPrimitiveArray<ImageSpaceEffectTexture*> effectTextures; // 40
    std::uint8_t unk58[0x40];                                   // 58
    ImageSpaceEffectTexture tex98;                              // 98
    ImageSpaceEffectTexture texB8;                              // B8
    ImageSpaceEffectTexture texD8;                              // D8
};
static_assert(offsetof(ImageSpaceEffectGetHit, effectTextures) == 0x40, "effectTextures offset");
static_assert(offsetof(ImageSpaceEffectGetHit, tex98) == 0x98, "tex98 offset");
static_assert(offsetof(ImageSpaceEffectGetHit, texB8) == 0xB8, "texB8 offset");
static_assert(offsetof(ImageSpaceEffectGetHit, texD8) == 0xD8, "texD8 offset");
