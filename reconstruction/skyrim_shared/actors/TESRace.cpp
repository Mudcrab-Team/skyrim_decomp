// Source exposure: mixed (pinned image listing, labelled declarations and Fallout 3 sibling source).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with a sibling helper.
// Adapted bodies: TestBit from the Fallout 3 sibling (CC0-1.0).
// TestBit: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// TESRace::QCanUseMeleeWeapons: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x3ebda0 TESRace::GetPlayable
// 0x3e6250 TESRace::GetBodyPartData
// 0x3ebd80 TESRace::GetFormEditorID
// 0x3e64a0 TESRace::GetMovementType
// 0x3eb840 TESRace::~TESRace
// 0x3e8300 TESRace::QCanUseMeleeWeapons
// 0x3e82e0 TESRace::Function3e82e0
// 0x3e8610 TESRace::Function3e8610
#include "TESRace.h"

namespace {
constexpr std::uint32_t kMeleeWeapons = 0x7E;
constexpr std::uint32_t kWeaponsAndSpells = 0x3FE;

// Test a flag by its bit index.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return (a_flags >> a_bit) & 1u;
}
}

// The constructor is not compared: it is defined so that this unit emits the vftable and with it
// the deleting destructor.
TESRace::TESRace()
{
}

bool TESRace::GetPlayable() const
{
    return TestBit(data.flags, 0);
}

BGSBodyPartData* TESRace::GetBodyPartData()
{
    return bodyPartData ? bodyPartData : defaultBodyPartData;
}

const char* TESRace::GetFormEditorID() const
{
    return formEditorID.c_str();
}

BGSMovementType* TESRace::GetMovementType(std::int32_t a_index)
{
    BGSMovementType* type = baseMoveTypes[a_index];
    if (type) {
        return type;
    }
    return BGSDefaultObjectManager::GetDefaultMovementType(a_index);
}
// Report whether this race can equip a melee weapon.
bool TESRace::QCanUseMeleeWeapons() const
{
    return GetValidEquipTypes(kMeleeWeapons) > 0;
}

// Report whether this race can equip a weapon, staff or spell.
bool TESRace::Function3e82e0() const
{
    return GetValidEquipTypes(kWeaponsAndSpells) > 0;
}

// Look up a face detail texture for the selected sex.
BGSTextureSet* TESRace::Function3e8610(std::int32_t a_sex, std::uint32_t a_index) const
{
    const FaceRelatedData* face = faceRelatedData[a_sex];
    if (face) {
        const auto* textures = face->faceDetailsTextureSets;
        if (textures && a_index < textures->size) {
            return textures->data[a_index];
        }
    }
    return nullptr;
}
