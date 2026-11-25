// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: Written for this reconstruction from the listing; ImageSpaceRange layout is a guess from the stores, and the range pair is written as one 64-bit store. Stamped as a twin of matched 0x15411e0 (bsshader/BSImagespaceShader): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// ImageSpaceEffectParam, ImageSpaceManager: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceSlot, ImageSpaceRenderState: GUESS(low)
// CopySubRegionRequest: GUESS(low)
// ImageSpaceRange: GUESS(low); layout inferred from the stores of Function15410e0
// Function15471e0, Owner15471e0: GUESS(low) STANDIN
// BSShader, unknown90, Unk_07, Unk_08, Unk_09, Unk_0A, Unk_0B, m_slots, m_slotCount, m_renderState, m_statesDirty, ResetRenderStates, IsReady: GUESS(low) STANDIN
#pragma once
#include "BSImagespaceShader.h"
#include <cstring>

class Owner15471e0 : public BSShader
{
public:
    virtual std::uint64_t* Unk_0D(std::uint64_t* a_out);
    virtual bool RestoreRenderStates(ImageSpaceEffectParam* a_param);
    virtual void UpdateParams(ImageSpaceEffectParam* a_param);
    virtual void Unk_0C(std::uint32_t a_x, std::uint32_t a_y, std::uint32_t a_z);
    virtual void ShutDown();
    // the image leaves the result of IsReady in AL on return; NG declares void
    virtual bool Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param);
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();

    bool ResetRenderStates();
    bool IsReady(std::uint32_t a_arg1, std::uint32_t a_arg2, std::uint32_t a_arg3);

    // The first qword of the request is a target object, not a vtable, so this stays a static function.
    static std::uint32_t DispatchCopySubRegion(struct CopySubRegionRequest* a_request);
    static void Function15471e0(struct CopySubRegionRequest* a_request);

    std::uint8_t unknown90[0x48];  // 90
    ImageSpaceSlot** m_slots;      // d8
    std::uint8_t unknownE0[0x98];  // e0
    std::uint32_t m_slotCount;     // 178
    std::uint8_t unknown17C[0x1C];  // 17c
    ImageSpaceRenderState* m_renderState;  // 198
    std::uint8_t unknown1A0[0x1];  // 1a0
    bool m_statesDirty;            // 1a1
    std::uint8_t unknown1A2[0x6];  // 1a2
public:
    std::uint64_t* GetShaderMacros(std::uint64_t* a_out);
public:
    static ImageSpaceRange* Function15410e0(ImageSpaceRange* a_result, void* a_value);
};
static_assert(sizeof(Owner15471e0) == 0x1A8, "Owner15471e0 size");
