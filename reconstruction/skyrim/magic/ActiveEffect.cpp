// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// ActiveEffect::GetVisualsTarget, ActiveEffect::CanFinish: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:12
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:203
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h, include/RE/M/MagicTarget.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5bb070 ActiveEffect::GetVisualsTarget
// 0x5d3e00 ActiveEffect::Function5d3e00
// Code origin: written for this reconstruction from the listing; names and layout from the unit header.
// Adapted bodies: none
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "ActiveEffect.h"
void* ActiveEffect::GetVisualsTarget() { return target ? target->GetTargetStatsObject() : nullptr; }
bool ActiveEffect::CanFinish() const { if (!(flags & 0x60) || (flags & 0x8000) || spell->IsPermanent()) return true; return false; }

void* ActiveEffect::Function5d3e00() { return VirtualSlot12(); }
