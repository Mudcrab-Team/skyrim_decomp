// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::SetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niintegersextradata_o2_variant.cpp:205
// ImageSpaceEffectWaterDisplacement, ImageSpaceEffectWaterDisplacement::Setup: CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceManager, ImageSpaceEffectParam, ImageSpaceShaderParam, NiTPrimitiveArray, ImageSpaceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffect::effectParams, ImageSpaceEffect::effectTextures: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MemoryManager, g_memoryManager, g_memoryManagerState, Initialize, Allocate, TargetBase0, TargetSub, TargetDerived, targets, width, height, SetAt, data, capacity, size, activeCount, growthSize, Function1553df0, Function150b8f0, Function150b630, Function1554150, unk00, unk0C, unk0D, unkA0, unk14C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class MemoryManager
{
public:
    void Initialize(std::uint32_t* a_state);                                           // callee at 0xcde810, not compared
    void* Allocate(std::size_t a_size, std::uint32_t a_align, bool a_alignRequired);  // callee at 0xcde250, not compared
};

extern MemoryManager g_memoryManager;
extern std::uint32_t g_memoryManagerState;

class ImageSpaceShaderParam
{
public:
    static void* operator new(std::size_t a_size)
    {
        if (g_memoryManagerState != 2) {
            g_memoryManager.Initialize(&g_memoryManagerState);
        }
        return g_memoryManager.Allocate(a_size, 0, false);
    }

    ImageSpaceShaderParam();                                    // callee at 0x152ae10, not compared
    void Function150b630(std::int32_t a_w, std::int32_t a_h);   // callee at 0x150b630, not compared

    std::uint8_t unk00[0x0C];  // 00
    std::uint8_t unk0C;        // 0C
    std::uint8_t unk0D[0x73];  // 0D
};
static_assert(sizeof(ImageSpaceShaderParam) == 0x80, "ImageSpaceShaderParam size");

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
            if (a_element) {
                if (!data[a_index]) {
                    ++activeCount;
                }
            } else if (data[a_index]) {
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

struct TargetBase0
{
    std::uint8_t unk00[0x90];
};
static_assert(sizeof(TargetBase0) == 0x90, "TargetBase0 size");

struct TargetSub
{
    std::uint8_t unk00[0x10];
};

struct TargetDerived : public TargetBase0, public TargetSub
{
    std::uint8_t unkA0[0xA8];   // A0
    std::int32_t width;         // 148
    std::uint8_t unk14C[0x14];  // 14C
    std::int32_t height;        // 160
};
static_assert(offsetof(TargetDerived, width) == 0x148, "width offset");
static_assert(offsetof(TargetDerived, height) == 0x160, "height offset");

struct ImageSpaceManager
{
    std::uint8_t unk00[0x28];
    TargetSub** targets;  // 28
};

class ImageSpaceEffectParam;
class ImageSpaceTexture;

void Function150b8f0(NiTPrimitiveArray<ImageSpaceTexture*>* a_textures, std::int32_t a_count);  // callee at 0x150b8f0, not compared

class ImageSpaceEffectWaterDisplacement
{
public:
    void Setup(ImageSpaceManager* a_mgr, ImageSpaceEffectParam* a_param);  // compared: 0x155b0f0
    void Function1553df0(std::int32_t a_count);                            // callee at 0x1553df0, not compared
    void Function1554150(std::int32_t a_a, TargetSub* a_sub, ImageSpaceShaderParam* a_p, std::int32_t a_d);  // callee at 0x1554150, not compared

    std::uint8_t unk00[0x28];                              // 00
    NiTPrimitiveArray<ImageSpaceShaderParam*> effectParams;  // 28
    NiTPrimitiveArray<ImageSpaceTexture*> effectTextures;  // 40
};
static_assert(offsetof(ImageSpaceEffectWaterDisplacement, effectTextures) == 0x40, "effectTextures offset");
