// Source exposure: mixed (pinned image and CommonLibSSE-NG).
// Code origin: original reconstruction using the family generator and community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SkyEffectController: EXE_RTTI
// GetTargetReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// playerReference: GUESS(low); stand-in for the player singleton pointer.
// Adapted bodies: none
// 0x5dd170 SkyEffectController::GetTargetReference
// CI hash: 0x5dd170 ?GetTargetReference@SkyEffectController@@UEAAPEAVTESObjectREFR@@XZ
#include "SkyEffectController_5dd170.h"

TESObjectREFR* SkyEffectController::GetTargetReference()
{
    return playerReference;
}
