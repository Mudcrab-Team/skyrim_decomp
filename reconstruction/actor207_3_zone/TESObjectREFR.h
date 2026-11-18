// TESObjectREFR: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, TESObjectCELL, TESWorldSpace, BGSEncounterZone, parentCell, encounterZone, GetWorldspace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// GetEncounterZone, GetCellZone, unknownPrefix: STANDIN GUESS(medium); direct callee name and ownership inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
namespace P2073 {
class BGSEncounterZone;
class TESObjectCELL { public: BGSEncounterZone* GetCellZone(); };
class TESWorldSpace { public: std::uint8_t unknownPrefix[0x220]; BGSEncounterZone* encounterZone; };
class TESObjectREFR {
public:
    BGSEncounterZone* GetEncounterZone();
    TESWorldSpace* GetWorldspace();
    std::uint8_t unknownPrefix[0x60];
    TESObjectCELL* parentCell;
};
}
