// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a1770 TESUseWeaponPackageData::TESUseWeaponPackageData
// Adapted bodies: TESUseWeaponPackageData::TESUseWeaponPackageData from fo4-private@1b765c70 src/Shared/AI/PackageDataUseWeapon.cpp:77 (see the header)
#include "TESUseWeaponPackageData_4a1770.h"

TESUseWeaponPackageData::TESUseWeaponPackageData(PACK_USE_WEAPON_DATA_PKW3 a_data)
{
    pAttackTarget = nullptr;
    pTargetLocation = nullptr;
    pWeapon = reinterpret_cast<TESObjectWEAP*>(static_cast<std::uintptr_t>(a_data.iWeapon));  // the plugin record holds a form ID; it is resolved in InitItem
    bAlwaysHit = a_data.bAlwaysHit;
    bDoNoDamage = a_data.bDoNoDamage;
    bCrouch = a_data.bCrouch;
    bHoldFire = a_data.bHoldFire;
    bVolleyFire = a_data.bVolleyFire;
    bRepeatFire = a_data.bRepeatFire;
    sBurstCount = a_data.sBurstCount;
    sVolleyShotsMin = a_data.sVolleyShotsMin;
    sVolleyShotsMax = a_data.sVolleyShotsMax;
    fVolleyWaitMin = a_data.fVolleyWaitMin;
    fVolleyWaitMax = a_data.fVolleyWaitMax;
}
