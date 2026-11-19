// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// 0x6ff380 AIProcess::ClearMuzzleFlashes
// 0x720660 AIProcess::GetCurrentWeapon
// 0x721f70 AIProcess::SetRunOncePackage
// 0x723510 AIProcess::SetHeadtrackTarget
// Adapted bodies: none
#include "AIProcess.h"

ActorPackageData* CreateActorPackageData(TESPackage* a_package, Actor* a_actor);

void AIProcess::ClearMuzzleFlashes()
{
    if (!high) {
        return;
    }

    delete high->muzzleFlash;
    high->muzzleFlash = nullptr;
}

InventoryEntryData* AIProcess::GetCurrentWeapon(bool a_leftHand) const
{
    if (!middleHigh) {
        return nullptr;
    }

    InventoryEntryData* entry = a_leftHand ? middleHigh->leftHand : middleHigh->rightHand;
    if (entry && (!entry->object || entry->object->formType != static_cast<std::uint8_t>(FormType::Weapon))) {
        return nullptr;
    }

    return entry;
}

void AIProcess::SetRunOncePackage(TESPackage* a_package, Actor* a_actor)
{
    if (!middleHigh) {
        return;
    }

    if (!a_package) {
        TESPackage* package = middleHigh->runOncePackage.package;
        middleHigh->runOncePackage.ClearPackage(a_actor);
        if (package) {
            ReleaseRunOncePackage();
        }
        ClearRunOncePackageData();
    } else {
        ActorPackageData* data = CreateActorPackageData(a_package, a_actor);
        middleHigh->runOncePackage.SetPackage(a_package, data, a_actor);
    }

    UpdateRunOncePackage();
}

void AIProcess::SetHeadtrackTarget(ActorPrefix* a_owner, NiPoint3& a_targetPosition)
{
    if (!middleHigh) {
        return;
    }

    middleHigh->unk326 = true;
    a_owner->unknown038.SetTarget(&GetHeadtrackData()->unknown490, a_targetPosition);
}
