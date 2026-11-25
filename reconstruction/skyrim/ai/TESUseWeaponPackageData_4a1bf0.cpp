// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a1bf0 TESUseWeaponPackageData::InitItem
// Adapted bodies: TESUseWeaponPackageData::InitItem from fo4-private@1b765c70 src/Shared/AI/PackageDataUseWeapon.cpp:234 (see the header)
#include "TESUseWeaponPackageData_4a1bf0.h"

void TESUseWeaponPackageData::InitItem(TESForm* a_owner)
{
    if (pAttackTarget)
        pAttackTarget->InitItem(a_owner);
    pWeapon = dynamic_cast<TESObjectWEAP*>(TESForm::LookupByID(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(pWeapon))));
}
