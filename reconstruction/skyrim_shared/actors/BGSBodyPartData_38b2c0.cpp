// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSBodyPartData::GetBodyPart, BGSBodyPartData::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSBodyPartData.cpp:143
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSBodyPartData.cpp:36
// BGSBodyPartData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSBodyPartData.h, include/RE/T/TESForm.h, include/RE/T/TESModel.h and include/RE/B/BGSPreloadable.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38b720 BGSBodyPartData::GetBodyPart
// 0x38b2c0 BGSBodyPartData::InitializeData
#include "BGSBodyPartData_38b2c0.h"
void BGSBodyPartData::InitializeData() { parts[0] = nullptr; parts[1] = nullptr; parts[2] = nullptr; parts[3] = nullptr; parts[4] = nullptr; parts[5] = nullptr; ragdoll = nullptr; }
