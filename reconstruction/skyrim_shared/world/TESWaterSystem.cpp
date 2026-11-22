// Source exposure: mixed (pinned image listing, sibling hint, community declarations).
// Code origin: existing sibling-adapted method plus original reconstruction of Function52d380.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Water/TESWater.cpp:159
// Adapted bodies: RemoveLODWater from fo4-private@1b765c70; Function52d380 original.
// 0x52d200 TESWaterSystem::RemoveLODWater
// 0x52d380 TESWaterSystem::Function52d380
#include "TESWaterSystem.h"
void TESWaterSystem::RemoveLODWater(NiAVObject* water, NiNode* root) { RemoveWater(water); root->DetachChild2(water->parent); }
void TESWaterSystem::Function52d380() { if (void* target = g_waterSystem->sub->target) ReleaseWaterTarget(target); }
