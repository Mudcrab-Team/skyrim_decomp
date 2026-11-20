// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// SpawnHazardEffect::HandleQueuedStart: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/SpawnHazardEffect.cpp:52
// ActiveEffect, SpawnHazardEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h, include/RE/S/SpawnHazardEffect.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x666bf0 SpawnHazardEffect::HandleQueuedStart
#include "SpawnHazardEffect.h"
void SpawnHazardEffect::HandleQueuedStart() { if (!((unsigned char)(flags >> 18) & 1)) SpawnHazard(); }
