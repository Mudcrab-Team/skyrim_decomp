// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// EtherealizationEffect::Start, EtherealizationEffect::Finish: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EtherealizationEffect.cpp:21
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EtherealizationEffect.cpp:38
// ActiveEffect, EtherealizationEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h and include/RE/E/EtherealizationEffect.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5c6e00 EtherealizationEffect::Start
// 0x5c6e30 EtherealizationEffect::Finish
#include "EtherealizationEffect.h"
void EtherealizationEffect::Start() { if (target) { Actor* actor = target->GetTargetAsActor(); if (actor) actor->SetGhost(true); } }
void EtherealizationEffect::Finish() { if (target) { Actor* actor = target->GetTargetAsActor(); if (actor) actor->SetGhost(false); } }
