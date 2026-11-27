// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESImagespaceManager::UpdateActiveEOFEffectCount: GUESS(low); the name comes from the inventory
// TESImagespaceManager: STANDIN GUESS(low); the name comes from the inventory; NG's ImageSpaceManager has the same members, only those the function reads or writes are declared
// ImageSpaceEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the virtual slots up to 06
// ImageSpaceEffect::IsActive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); virtual slot 06
// effects: GUESS(low); the name is NG's for the effect array of ImageSpaceManager, here only its element pointer at 28
// unk3C, unk40: GUESS(low); the placeholder names NG uses for ImageSpaceManager
// g_effectsEnabled: GUESS(low); a byte global the function tests
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void Render(void* a_shape, void* a_param);          // 01
    virtual void Setup(void* a_manager, void* a_param);         // 02
    virtual void ShutDown();                                    // 03
    virtual void BorrowTextures(void* a_param);                 // 04
    virtual void ReturnTextures();                              // 05
    virtual bool IsActive();                                    // 06
};

extern bool g_effectsEnabled;

class TESImagespaceManager
{
public:
    void UpdateActiveEOFEffectCount();  // compared: 0x14f4370

    std::uint8_t unk00[0x28];
    ImageSpaceEffect** effects;  // 28
    std::uint8_t unk30[0xc];
    std::uint32_t unk3C;         // 3C
    std::int32_t unk40;          // 40
};
static_assert(offsetof(TESImagespaceManager, unk40) == 0x40, "layout");
