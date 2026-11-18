// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// ReferenceEffectController::GetIsRootActor: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:5
// ReferenceEffectController, TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/R/ReferenceEffectController.h and include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5dbfb0 ReferenceEffectController::GetIsRootActor
#include "ReferenceEffectController.h"
bool ReferenceEffectController::GetIsRootActor() { TESObjectREFR* ref = GetTargetReference(); if (!ref) return false; TESObjectREFR* actor = ref->formType == 0x3e ? ref : nullptr; if (!actor) return false; return true; }
