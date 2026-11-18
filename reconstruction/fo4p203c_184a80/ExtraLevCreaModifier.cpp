// Source exposure: mixed
// Origin: original reconstruction from target and anonymous sibling, community declarations.
// names: GUESS(low); names and signatures are hypotheses.
// ExtraLevCreaModifier::GetMultiplier: SIBLING(fo4-private@1b765c70, author-permission); adapted lookup; target uses a member rather than the sibling parameter.
// Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataObjects.cpp:725
// ExtraLevCreaModifier, BSExtraData, Setting: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/E/ExtraLevCreaModifier.h, include/RE/B/BSExtraData.h and include/RE/S/Setting.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x184a80 ExtraLevCreaModifier::GetMultiplier
#include "ExtraLevCreaModifier.h"
float ExtraLevCreaModifier::GetMultiplier() const { auto index = static_cast<std::int32_t>(modifier); return static_cast<std::uint32_t>(index) <= 3 ? pLevCreaModMult[index]->data.f : 1.0f; }
