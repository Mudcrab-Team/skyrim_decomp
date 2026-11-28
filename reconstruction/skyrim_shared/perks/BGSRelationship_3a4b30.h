// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSRelationship, BGSRelationship::GetChildAssociationLabel, TESNPC, BGSAssociationType, npc2, assocType: CRASHLOGGER_PDB(59818@2026.10.24)
// GetSex, GetLabel: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class TESNPC
{
public:
    std::uint32_t GetSex() const;
};

class BGSAssociationType
{
public:
    const char* GetLabel(std::int32_t a_role, std::uint32_t a_sex) const;
};

class BGSRelationship
{
public:
    const char* GetChildAssociationLabel() const;

    std::uint8_t unk00[0x28];
    TESNPC* npc2;
    BGSAssociationType* assocType;
};

static_assert(offsetof(BGSRelationship, npc2) == 0x28, "npc2 offset");
static_assert(offsetof(BGSRelationship, assocType) == 0x30, "assocType offset");
