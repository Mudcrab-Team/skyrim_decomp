// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReferenceEffect, ReferenceEffect::~ReferenceEffect, ReferenceEffect::Detach, ReferenceEffect::Update, ReferenceEffect::GetManagerHandlesSaveLoad, ReferenceEffect::GetClearWhenCellIsUnloaded, ReferenceEffect::GetType, ReferenceEffect::SaveGame, ReferenceEffect::LoadGame, ReferenceEffect::FinishLoadGame, ReferenceEffect::Init, ReferenceEffect::Suspend, ReferenceEffect::Resume, ReferenceEffect::ClearTarget, ReferenceEffect::UpdateParentCell, ReferenceEffect::UpdatePosition, ReferenceEffect::GetAttachRoot, ReferenceEffect::GetAttached, ReferenceEffect::DetachImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReferenceEffect::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission)
// ReferenceEffect::controller, ReferenceEffect::target, ReferenceEffect::aimAtTarget, ReferenceEffect::finished, ReferenceEffect::ownController, ReferenceEffect::pad42, ReferenceEffect::pad44: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets 30, 38, 3C, 40, 41, 42, 44
// Slot31, Slot32, Slot33, Slot34, Slot35: GUESS(low); header-gap BSTempEffect (the shared header stops at slot 30, the image has Init at slot 36)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffect.cpp:51
#pragma once

#include <cstdint>
#include <cstddef>
#include "skyrim_shared/tempeffects/BSTempEffect.h"

class ReferenceEffectController;

class ReferenceEffect : public BSTempEffect
{
public:
    ~ReferenceEffect() override;  // 00
    void Detach() override;  // 27
    bool Update(float a_arg1) override;  // 28
    bool GetManagerHandlesSaveLoad() const override;  // 2A
    bool GetClearWhenCellIsUnloaded() const override;  // 2B
    TEMP_EFFECT_TYPE GetType() const override;  // 2C
    void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 2D
    void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 2E
    void FinishLoadGame(BGSLoadGameBuffer* a_buf) override;  // 2F
    virtual void Slot31();  // 31
    virtual void Slot32();  // 32
    virtual void Slot33();  // 33
    virtual void Slot34();  // 34
    virtual void Slot35();  // 35
    virtual void Init();  // 36
    virtual void Suspend();  // 37
    virtual void Resume();  // 38
    virtual void ClearTarget();  // 39
    virtual void UpdateParentCell(NiAVObject* a_object);  // 3A
    virtual void UpdatePosition();  // 3B
    virtual NiAVObject* GetAttachRoot();  // 3C
    virtual bool GetAttached();  // 3D
    virtual void DetachImpl();  // 3E

    ReferenceEffectController* controller;  // 30
    std::uint32_t target;                   // 38
    std::uint32_t aimAtTarget;              // 3C
    bool finished;                          // 40
    bool ownController;                     // 41
    std::uint16_t pad42;                    // 42
    std::uint32_t pad44;                    // 44
};
static_assert(sizeof(ReferenceEffect) == 0x48, "ReferenceEffect size");
