// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectREFR::SetActorCause: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// TESObjectREFR::GetAnimationGraphManagerImpl: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior; target uses animation holder.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_ExtraData.cpp:378
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_Animation.cpp:71
// TESForm, TESObjectREFR: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x300c90 TESObjectREFR::SetActorCause
// 0x2fd720 TESObjectREFR::GetAnimationGraphManagerImpl
#include "TESObjectREFR_2fd720.h"
void TESObjectREFR::SetActorCause(ActorCause* cause) { extraList.SetActorCauseExtra(cause); AddChange(0x80000000u); }
bool TESObjectREFR::GetAnimationGraphManagerImpl(AnimationGraphPointer& out) const { IAnimationGraphManagerHolder::GetAnimationGraphManager(out); return out.ptr != nullptr; }
