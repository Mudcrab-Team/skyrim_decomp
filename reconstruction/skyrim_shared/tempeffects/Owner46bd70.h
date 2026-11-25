// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: original reconstruction from binary analysis; no external implementation code copied. Stamped as a twin of matched 0x5dc660 (skyrim_shared/tempeffects/ActiveEffectReferenceEffectController): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPoint3, TESEffectShader, BGSArtObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); three floats only
// ActiveEffectOwner, ReferenceTarget: GUESS(low)
// Function46bd70, Owner46bd70: GUESS(low) STANDIN
// ReferenceEffectController: GUESS(low) STANDIN
#pragma once
#include "ActiveEffectReferenceEffectController.h"

class Owner46bd70 : public ReferenceEffectController
{
public:
    virtual float GetElapsedTime();
    virtual bool GetNoInitialFlare();
    virtual const NiPoint3& GetSourcePosition();
    virtual bool GetEffectPersists();
    virtual bool GetGoryVisuals();
    virtual TESEffectShader* GetHitEffectShader();
    virtual BGSArtObject* GetHitEffectArt();
    void Function46bd70(ReferenceTarget* a_target);

    ActiveEffectOwner* owner;  // 0x08
    unsigned char padTwin10[80];
    std::uint32_t targetHandle;  // 0x10
    std::uint8_t unknown14[0xC];  // 0x14
};
static_assert(sizeof(Owner46bd70) == 0x70, "Owner46bd70 size");
