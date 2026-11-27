// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// ImageSpaceEffectDepthOfField, ImageSpaceEffectDepthOfField::BorrowTextures: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTPrimitiveArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffectTexture, Global333d40a0, RenderTargetTable3335600, g_global333d40a0, g_renderTargetTable, Function1554f40, Function1554f90, Function1015790, Function153c8f0, SetAt, data, capacity, size, activeCount, growthSize, textures, flag210, flags98, texA8, texC8, texE8, tex108, tex128, unk00, unk08, unk58, unkA0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectTexture
{
public:
    void Function1554f40(std::int32_t a_arg);  // callee at 0x1554f40, not compared
    void Function1554f90(std::int32_t a_arg);  // callee at 0x1554f90, not compared

    std::uint8_t unk00[0x20];
};
static_assert(sizeof(ImageSpaceEffectTexture) == 0x20, "ImageSpaceEffectTexture size");

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

struct Global333d40a0
{
    std::uint8_t unk00[0x210];
    std::uint8_t flag210;  // 210
};

struct RenderTargetTable3335600
{
    std::int32_t Function1015790();  // callee at 0x1015790, not compared
};

extern Global333d40a0* g_global333d40a0;
extern RenderTargetTable3335600 g_renderTargetTable;

std::int32_t Function153c8f0();  // callee at 0x153c8f0, not compared

class ImageSpaceEffectDepthOfField
{
public:
    virtual ~ImageSpaceEffectDepthOfField();

    void BorrowTextures();  // compared: 0x1551820

    std::uint8_t unk08[0x38];
    NiTPrimitiveArray<ImageSpaceEffectTexture*> textures;  // 40
    std::uint8_t unk58[0x40];                              // 58
    std::uint8_t* flags98;                                 // 98
    std::uint8_t unkA0[0x08];                              // A0
    ImageSpaceEffectTexture texA8;                         // A8
    ImageSpaceEffectTexture texC8;                         // C8
    ImageSpaceEffectTexture texE8;                         // E8
    ImageSpaceEffectTexture tex108;                        // 108
    ImageSpaceEffectTexture tex128;                        // 128
};
static_assert(offsetof(ImageSpaceEffectDepthOfField, tex128) == 0x128, "tex128 offset");
