// Source exposure: mixed. Existing bodies were drafted by claude-sonnet-5-5 from the pinned image.
// Code origin: original reconstruction from the pinned image and community declarations; GetMountInteraction from the listing and the CrashLogger PDB name.; the seven added Actor functions from the listings and the CrashLogger and FO4 names
// Adapted bodies: none in this change.
// FindOutfitExtra: GUESS(low); callee of HasOutfitItems.
// TESRace::GetBodyPartData: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); callee at RVA 0x3e6250 compared in another unit
// bodyPartOverride bodyPartOverrideActor: GUESS(low); globals at RVA 0x31e0180 and 0x31df300, a body part data and the actor it applies to
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x681d60 Actor::IsAlarmed
// 0x671af0 Actor::GetBodyPartData
// 0x6c90b0 Actor::GetCombatState
// 0x677330 Actor::OnAddCellPerformQueueReference
// 0x6b1620 Actor::UpdateFadeSettings
// 0x67f620 Actor::CheckForCurrentAliasPackage
// 0x31e0180
#include "Actor_671af0.h"

// RACE_DATA, RACE_DATA::Flag, kFlies, TESRace::data, RACE_DATA::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20 to unknown100: GUESS(low); the race bases and members before data, as unresolved words at their offsets.
struct RACE_DATA {
    enum Flag : std::uint32_t { kFlies = 1u << 7 };
    Flag flags;
};

class TESRace {
public:
    virtual ~TESRace();
    BGSBodyPartData* GetBodyPartData();
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
    std::uint64_t unknown80;  // 80
    std::uint64_t unknown88;  // 88
    std::uint64_t unknown90;  // 90
    std::uint64_t unknown98;  // 98
    std::uint64_t unknownA0;  // A0
    std::uint64_t unknownA8;  // A8
    std::uint64_t unknownB0;  // B0
    std::uint64_t unknownB8;  // B8
    std::uint64_t unknownC0;  // C0
    std::uint64_t unknownC8;  // C8
    std::uint64_t unknownD0;  // D0
    std::uint64_t unknownD8;  // D8
    std::uint64_t unknownE0;  // E0
    std::uint64_t unknownE8;  // E8
    std::uint64_t unknownF0;  // F0
    std::uint64_t unknownF8;  // F8
    std::uint64_t unknown100;  // 100
    RACE_DATA data;  // 108
};

// TESRace::GetBodyPartData: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); callee at RVA 0x3e6250
extern BGSBodyPartData* bodyPartOverride;

extern Actor* bodyPartOverrideActor;

extern BGSBodyPartData* defaultBodyPartData;

static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

bool Actor::IsAlarmed()
{
    return currentProcess && currentProcess->unk20 && currentProcess->unk20->unk24 == 0x15;
}

BGSBodyPartData* Actor::GetBodyPartData() const
{
    BGSBodyPartData* data = nullptr;
    if (bodyPartOverride && this == bodyPartOverrideActor) {
        data = bodyPartOverride;
    }
    if (!data && race) {
        data = race->GetBodyPartData();
    }
    if (!data) {
        data = defaultBodyPartData;
    }
    return data;
}

ACTOR_COMBAT_STATE Actor::GetCombatState() const
{
    if (IsInCombat()) {
        const auto* group = GetCombatGroup();
        if (group && group->searchState > 0) {
            return ACTOR_COMBAT_STATE::kSearching;
        }
        return ACTOR_COMBAT_STATE::kCombat;
    }
    return ACTOR_COMBAT_STATE::kNone;
}

bool Actor::OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const
{
    return !PlayerCharacter::singleton->Function741350() && a_cell.cellState != 3;
}

void Actor::UpdateFadeSettings(bhkCharacterController* a_controller)
{
    if (a_controller) {
        const NiAVObject* node = Get3D2();
        const bool        far  = node ? TestBit(node->flags, 20) : true;
        const auto        bit  = static_cast<std::uint32_t>(CHARACTER_FLAGS::kFarAway);
        const auto        word = static_cast<std::uint32_t>(a_controller->flags);
        if (far) {
            a_controller->flags = static_cast<CHARACTER_FLAGS>(word | bit);
        } else {
            a_controller->flags = static_cast<CHARACTER_FLAGS>(word & ~bit);
        }
    }
}

TESPackage* Actor::CheckForCurrentAliasPackage()
{
    ExtraDataList* list = &extraList;
    if (list && !IsDead(true) && GetLifeState() != ACTOR_LIFE_STATE::kReanimate) {
        return list->GetAliasPackage(this);
    }
    return nullptr;
}
