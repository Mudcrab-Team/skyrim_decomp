// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layout follows the pinned field accesses and cited declarations.
// TESObjectWEAP, ::weaponData, ::Data, ::Data::animationType, ::IsRanged, ::IsBow, ::IsCrossbow: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WEAPON_TYPE, kBow, kStaff, kCrossbow: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsRangedWithoutAmmo: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

enum class WEAPON_TYPE : std::uint8_t
{
    kBow = 7,
    kStaff = 8,
    kCrossbow = 9
};

class TESObjectWEAP
{
public:
    struct Data
    {
        std::uint8_t unk00[0x35];   // 00
        WEAPON_TYPE  animationType; // 35
    };

    bool IsRangedWithoutAmmo() const;

    // The ranged types are the bow, staff and crossbow range.
    bool IsRanged() const
    {
        return weaponData.animationType >= WEAPON_TYPE::kBow && weaponData.animationType <= WEAPON_TYPE::kCrossbow;
    }

    bool IsBow() const
    {
        return weaponData.animationType == WEAPON_TYPE::kBow;
    }

    bool IsCrossbow() const
    {
        return weaponData.animationType == WEAPON_TYPE::kCrossbow;
    }

    std::uint8_t unknown000[0x168];  // 000 - TESBoundObject and the form components
    Data         weaponData;         // 168 - DNAM
};
static_assert(offsetof(TESObjectWEAP, weaponData) == 0x168, "layout differs from CommonLibSSE-NG");
