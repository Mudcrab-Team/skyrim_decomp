// Source exposure: mixed (pinned image and CommonLibSSE-NG).
// Code origin: original reconstruction using the family generator and community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SkyEffectController: EXE_RTTI
// GetTargetReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// playerReference: GUESS(low); stand-in for the player singleton pointer.
// Adapted bodies: none
#pragma once

class TESObjectREFR;
extern TESObjectREFR* playerReference;

class SkyEffectController
{
public:
    virtual TESObjectREFR* GetTargetReference();
};
