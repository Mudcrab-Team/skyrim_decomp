// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a1720 TESUseWeaponPackageData::TESUseWeaponPackageData
// Adapted bodies: TESUseWeaponPackageData::TESUseWeaponPackageData from fo4-private@1b765c70 src/Shared/AI/PackageDataUseWeapon.cpp:58 (see the header)
#include "TESUseWeaponPackageData_4a1720.h"

TESUseWeaponPackageData::TESUseWeaponPackageData()
{
    bAlwaysHit = false;
    bDoNoDamage = false;
    bCrouch = true;
    bHoldFire = true;
    bVolleyFire = false;
    bRepeatFire = false;
    sBurstCount = 1;
    sVolleyShotsMin = 1;
    sVolleyShotsMax = 6;
    fVolleyWaitMin = 1.0f;
    fVolleyWaitMax = 2.0f;
    pAttackTarget = nullptr;
    pTargetLocation = nullptr;
    pWeapon = nullptr;
}
