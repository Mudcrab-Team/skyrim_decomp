// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing, community declarations and the CrashLogger PDB names and layout only
// 0x6f1390 AIProcess::GetLastSeenLocation
// 0x6f1bd0 AIProcess::Function6f1bd0
// 0x6f2520 AIProcess::Function6f2520
// 0x6f2540 AIProcess::Function6f2540
// 0x6ff190 AIProcess::Function6ff190
// 0x6ff1e0 AIProcess::Function6ff1e0
// 0x6ff210 AIProcess::Function6ff210
// 0x6ff230 AIProcess::Function6ff230
// 0x6ff250 AIProcess::Function6ff250
// 0x6ff360 AIProcess::Function6ff360
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

NiPoint3* AIProcess::GetLastSeenLocation()
{
    return high ? &middleHigh->lastSeenPosition : nullptr;
}

void AIProcess::Function6f1bd0(bool a_value)
{
    if (high) {
        high->unk465 = a_value;
    }
}

void AIProcess::Function6f2520()
{
    if (high) {
        high->unk298 = 0.0f;
    }
}

DetectionEvent* AIProcess::Function6f2540()
{
    if (high) {
        return high->actorsGeneratedDetectionEvent;
    }

    return nullptr;
}

bool AIProcess::Function6ff190()
{
    if (high && high->unk46A) {
        return true;
    }

    return false;
}

float AIProcess::Function6ff1e0()
{
    if (high) {
        return high->deathForce;
    }

    return 1.0f;
}

void AIProcess::Function6ff210(float a_value)
{
    if (high) {
        high->deathForce = a_value;
    }
}

void AIProcess::Function6ff230()
{
    if (high) {
        high->deathForce = defaultDeathForce;
    }
}

NiPoint3* AIProcess::Function6ff250()
{
    if (high) {
        return &high->deathForceDirection;
    }

    return &defaultDeathForceDirection;
}

HighProcessData::MuzzleFlash* AIProcess::Function6ff360()
{
    if (high) {
        return high->muzzleFlash;
    }

    return nullptr;
}
