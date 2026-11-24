// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: names, slot order and member offsets from CharmedBaryon/CommonLibSSE-NG (MIT); only what the destructor uses is modelled
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReferenceEffect, ReferenceEffect::~ReferenceEffect, ReferenceEffect::controller, ReferenceEffect::target, ReferenceEffect::aimAtTarget, ReferenceEffect::finished, ReferenceEffect::ownController, ReferenceEffect::pad42, ReferenceEffect::pad44, ReferenceEffectController, ReferenceEffectController::~ReferenceEffectController, ReferenceEffectController::RemoveHitEffect, ReferenceEffectController::HandleEvent, ReferenceEffectController::GetElapsedTime, ReferenceEffectController::GetScale, ReferenceEffectController::SwitchAttachedRoot, ReferenceEffectController::GetSourcePosition, ReferenceEffectController::GetUseSourcePosition, ReferenceEffectController::GetNoInitialFlare, ReferenceEffectController::GetEffectPersists, ReferenceEffectController::GetGoryVisuals: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTempEffect, BSTempEffect::~BSTempEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the base members are one padding block
// BSUntypedPointerHandle, BSUntypedPointerHandle::iBits, BSUntypedPointerHandle::hNull: SIBLING(fo4-private@1b765c70, author-permission); the handle type and its null constant as the sibling destructor writes them
// pad08: GUESS
#pragma once

#include <cstddef>

class BSFixedString;
class NiNode;
class NiPoint3;
class ReferenceEffect;

struct BSUntypedPointerHandle
{
    unsigned int iBits;
    static BSUntypedPointerHandle hNull;
};

class ReferenceEffectController
{
public:
    virtual ~ReferenceEffectController();                                          // 00
    virtual void HandleEvent(const BSFixedString& a_event);                        // 01
    virtual float GetElapsedTime();                                                // 02
    virtual float GetScale();                                                      // 03
    virtual void SwitchAttachedRoot(NiNode* a_root, NiNode* a_attachRoot);         // 04
    virtual const NiPoint3& GetSourcePosition();                                   // 05
    virtual bool GetUseSourcePosition();                                           // 06
    virtual bool GetNoInitialFlare();                                              // 07
    virtual bool GetEffectPersists();                                              // 08
    virtual bool GetGoryVisuals();                                                 // 09
    virtual void RemoveHitEffect(ReferenceEffect* a_refEffect);                    // 0A
};

class BSTempEffect
{
public:
    virtual ~BSTempEffect();  // 00
    unsigned char pad08[0x28];  // 08
};
static_assert(sizeof(BSTempEffect) == 0x30, "BSTempEffect size");

class ReferenceEffect : public BSTempEffect
{
public:
    ~ReferenceEffect() override;  // 00, compared: 0x5db120

    ReferenceEffectController* controller;  // 30
    BSUntypedPointerHandle target;          // 38
    BSUntypedPointerHandle aimAtTarget;     // 3C
    bool finished;                          // 40
    bool ownController;                     // 41
    unsigned short pad42;                   // 42
    unsigned int pad44;                     // 44
};
static_assert(sizeof(ReferenceEffect) == 0x48, "ReferenceEffect size");
