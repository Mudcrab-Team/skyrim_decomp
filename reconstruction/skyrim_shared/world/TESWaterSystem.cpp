// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// TESWaterSystem::RemoveLODWater: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Water/TESWater.cpp:159
// NiObject, NiAVObject, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/N/NiObject.h, include/RE/N/NiObjectNET.h, include/RE/N/NiAVObject.h and include/RE/N/NiNode.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x52d200 TESWaterSystem::RemoveLODWater
#include "TESWaterSystem.h"
void TESWaterSystem::RemoveLODWater(NiAVObject* water, NiNode* root) { RemoveWater(water); root->DetachChild2(water->parent); }
