// Source exposure: mixed
// Origin: original reconstruction from target and anonymous sibling, community declarations.
// names: GUESS(low); names and signatures are hypotheses.
// ExtraLevCreaModifier::GetMultiplier: SIBLING(fo4-private@1b765c70, author-permission); adapted lookup; target uses a member rather than the sibling parameter.
// Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataObjects.cpp:725
// ExtraLevCreaModifier, BSExtraData, Setting: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/E/ExtraLevCreaModifier.h, include/RE/B/BSExtraData.h and include/RE/S/Setting.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
enum class LEV_CREA_MODIFIER : std::int32_t { kEasy, kMedium, kHard, kVeryHard, kNone };
class Setting { public: virtual ~Setting(); union Data { bool b; float f; std::int32_t i; char* s; std::uint32_t u; } data; char* name; };
extern Setting* pLevCreaModMult[4];
class ExtraLevCreaModifier : public BSExtraData { public: float GetMultiplier() const; LEV_CREA_MODIFIER modifier; };
