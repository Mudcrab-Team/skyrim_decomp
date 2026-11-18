// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BanishEffect::Start: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/TargetValueModifierEffect.cpp:132
// BanishEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/B/BanishEffect.h.
// names: GUESS(low); method signatures and local names are inferred.
// 0x5e5770 BanishEffect::Start
#include "BanishEffect.h"
void BanishEffect::Start() { Actor* actor = target ? target->GetTargetAsActor() : nullptr; if (CheckSummonedActor(actor, true)) magnitude = 0.0f; else ResearchLayouts::TargetValueModifierEffectLayout::Start(); }
