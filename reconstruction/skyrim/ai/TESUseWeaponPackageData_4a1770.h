// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataUseWeapon.cpp:77
// TESUseWeaponPackageData, TESUseWeaponPackageData::TESUseWeaponPackageData, PackageTarget::InitItem: SIBLING(fo4-private@1b765c70, author-permission)
// PACK_USE_WEAPON_DATA_PKW3, PackageTarget: GUESS(medium); names from the sibling body, layout read from the listing
// TESForm::LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm, TESObjectWEAP: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00, unknown2c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm
{
public:
    virtual ~TESForm();  // 00

    static TESForm* LookupByID(std::uint32_t a_formID);
};

class TESObjectWEAP : public TESForm
{
};

class PackageTarget
{
public:
    void InitItem(TESForm* a_owner);
};

class PackageLocation;

struct PACK_USE_WEAPON_DATA_PKW3
{
    std::uint8_t bAlwaysHit;      // 00
    std::uint8_t bDoNoDamage;     // 01
    std::uint8_t bCrouch;         // 02
    std::uint8_t bHoldFire;       // 03
    std::uint8_t bVolleyFire;     // 04
    std::uint8_t bRepeatFire;     // 05
    std::uint16_t sBurstCount;    // 06
    std::uint16_t sVolleyShotsMin; // 08
    std::uint16_t sVolleyShotsMax; // 0A
    float fVolleyWaitMin;         // 0C
    float fVolleyWaitMax;         // 10
    std::uint32_t iWeapon;        // 14
};
static_assert(sizeof(PACK_USE_WEAPON_DATA_PKW3) == 0x18, "PACK_USE_WEAPON_DATA_PKW3 size");

class TESPackageData
{
public:
    virtual ~TESPackageData();  // 00
};

class TESUseWeaponPackageData : public TESPackageData
{
public:
    TESUseWeaponPackageData(PACK_USE_WEAPON_DATA_PKW3 a_data);
    PackageTarget* pAttackTarget;       // 08
    PackageLocation* pTargetLocation;   // 10
    std::uint8_t bAlwaysHit;            // 18
    std::uint8_t bDoNoDamage;           // 19
    std::uint8_t bCrouch;               // 1A
    std::uint8_t bHoldFire;             // 1B
    std::uint8_t bVolleyFire;           // 1C
    std::uint8_t bRepeatFire;           // 1D
    std::uint16_t sBurstCount;          // 1E
    std::uint16_t sVolleyShotsMin;      // 20
    std::uint16_t sVolleyShotsMax;      // 22
    float fVolleyWaitMin;               // 24
    float fVolleyWaitMax;               // 28
    std::uint8_t unknown2c[0x4];        // 2C
    TESObjectWEAP* pWeapon;             // 30
};
static_assert(sizeof(TESUseWeaponPackageData) == 0x38, "TESUseWeaponPackageData size");
