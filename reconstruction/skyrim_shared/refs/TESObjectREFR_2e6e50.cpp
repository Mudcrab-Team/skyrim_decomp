// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectREFR::GetExclusiveBranch, TESObjectREFR::SetExclusiveBranch: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// TESObjectREFR::GetActorCause: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:3594
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:3603
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_ExtraData.cpp:369
// ExtraSayToTopicInfo, ExtraActorCause, BSExtraData: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/E/ExtraSayToTopicInfo.h, include/RE/E/ExtraActorCause.h and include/RE/B/BSExtraData.h.
// TESForm, TESObjectREFR: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h, include/RE/T/TESObjectREFR.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e6e50 TESObjectREFR::GetExclusiveBranch
// 0x2e6e80 TESObjectREFR::SetExclusiveBranch
// 0x300cc0 TESObjectREFR::GetActorCause
#include "TESObjectREFR_2e6e50.h"
BGSDialogueBranch* TESObjectREFR::GetExclusiveBranch() const { auto p = extraList.GetSayToExtra(); return p ? p->exclusiveBranch : nullptr; }
void TESObjectREFR::SetExclusiveBranch(BGSDialogueBranch* branch) { auto p = extraList.GetSayToExtra(); if (p) p->exclusiveBranch = branch; }
ActorCause* TESObjectREFR::GetActorCause() const { auto p = extraList.GetActorCauseExtra(); return p ? p->actorCause : nullptr; }
