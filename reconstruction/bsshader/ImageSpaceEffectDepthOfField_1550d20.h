// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::GetAt, NiTPrimitiveArray::SetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00b80000_o2.cpp:3433
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niintegersextradata_o2_variant.cpp:205
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceEffectDepthOfField, ImageSpaceEffectDepthOfField::Setup, ImageSpaceManager, ImageSpaceShaderParam, NiTPrimitiveArray, MemoryManager, MemoryManager::GetSingleton: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceManager::effects: CRASHLOGGER_PDB(59818@2026.10.24)
// g_memoryManager, g_memoryManagerState, TargetBase0, TargetSub, TargetDerived, GetAt, GetWidth, GetHeight, DofShaderParams, g_dofParams20d7410, kPassCount, kDofParamSize, kSlot0, kSlot1, kSlot2, kSlot3, kSlot4, kSlot5, kSlot6, helpers: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class MemoryManager
{
public:
    static MemoryManager* GetSingleton();
    void Initialize(std::uint32_t* a_state);                                           // callee at 0xcde810, not compared
    void* Allocate(std::size_t a_size, std::uint32_t a_align, bool a_alignRequired);  // callee at 0xcde250, not compared
};

struct DofShaderParams
{
    std::uint8_t unk00[0x40];
};
static_assert(sizeof(DofShaderParams) == 0x40, "DofShaderParams size");

extern MemoryManager g_memoryManager;
extern std::uint32_t g_memoryManagerState;
extern DofShaderParams g_dofParams20d7410;

inline MemoryManager* MemoryManager::GetSingleton()
{
    if (g_memoryManagerState != 2) {
        g_memoryManager.Initialize(&g_memoryManagerState);
    }
    return &g_memoryManager;
}

class ImageSpaceShaderParam
{
public:
    static void* operator new(std::size_t a_size)
    {
        return MemoryManager::GetSingleton()->Allocate(a_size, 0, false);
    }

    ImageSpaceShaderParam();                                                   // callee at 0x152ae10, not compared
    void Function150b630(std::int32_t a_w, std::int32_t a_h);                  // callee at 0x150b630, not compared
    void Function152b1e0();                                                    // callee at 0x152b1e0, not compared
    void Function152b1b0(std::int32_t a_idx, void* a_data, std::int32_t a_n);  // callee at 0x152b1b0, not compared

    std::uint8_t unk00[0x80];
};
static_assert(sizeof(ImageSpaceShaderParam) == 0x80, "ImageSpaceShaderParam size");

template <class T>
class NiTPrimitiveArray
{
public:
    virtual ~NiTPrimitiveArray();

    T GetAt(std::uint32_t a_index) const
    {
        return data[a_index];
    }

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
    std::int32_t GetWidth() const { return width; }
    std::int32_t GetHeight() const { return height; }

    std::uint8_t unkA0[0xA8];   // A0
    std::int32_t width;         // 148
    std::uint8_t unk14C[0x14];  // 14C
    std::int32_t height;        // 160
};
static_assert(offsetof(TargetDerived, width) == 0x148, "width offset");
static_assert(offsetof(TargetDerived, height) == 0x160, "height offset");

struct ImageSpaceManager
{
    std::uint8_t unk00[0x20];
    NiTPrimitiveArray<TargetSub*> effects;  // 20
};
static_assert(offsetof(ImageSpaceManager, effects) == 0x20, "ImageSpaceManager effects offset");

class ImageSpaceEffectParam;

class ImageSpaceEffectDepthOfField
{
public:
    enum : std::int32_t
    {
        kPassCount = 5,
        kDofParamSize = 0x40,
        kSlot0 = 0,
        kSlot1 = 1,
        kSlot2 = 2,
        kSlot3 = 3,
        kSlot4 = 4,
        kSlot5 = 5,
        kSlot6 = 6
    };

    void Setup(ImageSpaceManager* a_mgr, ImageSpaceEffectParam* a_param);  // compared: 0x1550d20
    void Function1553df0(std::int32_t a_count);                            // callee at 0x1553df0, not compared
    void Function1554270(std::int32_t a_a, std::int32_t a_b, std::int32_t a_c);  // callee at 0x1554270, not compared
    void Function1554310(std::int32_t a_a, std::int32_t a_b, std::int32_t a_c, std::int32_t a_d, std::int32_t a_e);  // callee at 0x1554310, not compared
    void Function1554480(std::int32_t a_0, std::int32_t a_1, std::int32_t a_2, std::int32_t a_3, std::int32_t a_4,
        std::int32_t a_5, std::int32_t a_6, std::int32_t a_7, std::int32_t a_8);  // callee at 0x1554480, not compared
    void Function1554550(std::int32_t a_0, std::int32_t a_1, std::int32_t a_2, std::int32_t a_3, std::int32_t a_4,
        std::int32_t a_5, std::int32_t a_6, std::int32_t a_7, std::int32_t a_8, std::int32_t a_9, std::int32_t a_10);  // callee at 0x1554550, not compared
    void Function1554150(std::int32_t a_a, TargetSub* a_sub, ImageSpaceShaderParam* a_p, std::int32_t a_d);  // callee at 0x1554150, not compared

    std::uint8_t unk00[0x28];                              // 00
    NiTPrimitiveArray<ImageSpaceShaderParam*> effectParams;  // 28
};
static_assert(offsetof(ImageSpaceEffectDepthOfField, effectParams) == 0x28, "effectParams offset");
