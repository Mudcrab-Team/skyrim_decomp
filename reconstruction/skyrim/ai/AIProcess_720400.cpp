// Source exposure: mixed (pinned image listings, project AIProcess, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies using the cited process layout, except the method below.
// Adapted bodies: Set3DUpdateFlag follows CommonLibSSE-NG@b93280e src/RE/A/AIProcess.cpp:237 (MIT).
// 0x720400 AIProcess::IsPickPocketed
// 0x7206a0 AIProcess::GetBothHands
// 0x720700 AIProcess::GetLeftHand
// 0x720720 AIProcess::GetRightHand
// 0x721330 AIProcess::GetWeaponBone
// 0x721350 AIProcess::SetWeaponBone
// 0x7216a0 AIProcess::Function7216a0
// 0x7216c0 AIProcess::Function7216c0
// 0x7219f0 AIProcess::GetAnimationVariableCache
// 0x721a10 AIProcess::Function721a10
// 0x721f30 AIProcess::Function721f30
// 0x721f50 AIProcess::Function721f50
// 0x722050 AIProcess::SetRunOnceProcedureIndex
// 0x722070 AIProcess::GetRunOnceProcedureIndex
// 0x722090 AIProcess::AdvanceRunOnceProcedureIndex
// 0x7220b0 AIProcess::GetRunOncePackageData
// 0x7232d0 AIProcess::GetLastIdlePlayed
// 0x723330 AIProcess::GetCurrentMovementSpeed
// 0x723350 AIProcess::SetCurrentMovementSpeed
// 0x723390 AIProcess::Function723390
// 0x7233b0 AIProcess::GetRotation
// 0x7233d0 AIProcess::GetMoveDirectionRelativeToFacing
// 0x723580 AIProcess::Function723580
// 0x7245a0 AIProcess::Function7245a0
// 0x7245c0 AIProcess::Function7245c0
// 0x724600 AIProcess::Set3DUpdateFlag
// 0x724640 AIProcess::Clear3DUpdateFlags
#include "AIProcess_720400.h"

#include <cstddef>

// ActorPackage, packageLock, package, data, target, currentProcedureIndex: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSpinLock, Lock, _owningThread, _lockCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// niPointZero, padding: STANDIN GUESS(low)
class BSSpinLock
{
public:
    void Lock(std::uint32_t pauseAttempts);

private:
    std::uint32_t _owningThread;
    std::uint32_t _lockCount;
};

struct ActorPackage
{
    BSSpinLock packageLock;
    TESPackage* package;
    ActorPackageData* data;
    std::uint32_t target;
    std::int32_t currentProcedureIndex;
    std::uint8_t padding[0x10];
};
static_assert(sizeof(ActorPackage) == 0x30, "ActorPackage size");

class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

extern "C" NiPoint3 niPointZero;

// runOncePackage, rotation, weaponBone, animationVariableCache, unk1E8: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// leftHand, rightHand, bothHands, lastIdlePlayed, currentMovementSpeed, unk2AC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk310, update3DModel, unk317, unk318, pickPocketed, unk326: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct MiddleHighProcessData
{
    std::uint8_t padding000[0x58];
    ActorPackage runOncePackage;
    std::uint8_t padding088[0x28];
    NiPoint3 rotation;
    std::uint8_t padding0BC[0x94];
    NiNode* weaponBone;
    std::uint8_t padding158[0x58];
    BSAnimationGraphVariableCache* animationVariableCache;
    std::uint8_t padding1B8[0x30];
    BSSpinLock unk1E8;
    std::uint8_t padding1F0[0x30];
    InventoryEntryData* leftHand;
    std::uint8_t padding228[0x38];
    InventoryEntryData* rightHand;
    InventoryEntryData* bothHands;
    std::uint8_t padding270[0x10];
    TESIdleForm* lastIdlePlayed;
    std::uint8_t padding288[0x20];
    float currentMovementSpeed;
    float unk2AC;
    std::uint8_t padding2B0[0x60];
    std::uint8_t unk310;
    std::uint8_t update3DModel;
    std::uint8_t padding312[0x5];
    bool unk317;
    bool unk318;
    std::uint8_t padding319[0x2];
    bool pickPocketed;
    std::uint8_t padding31C[0xA];
    bool unk326;
};
static_assert(offsetof(MiddleHighProcessData, runOncePackage) == 0x58, "run-once package offset");
static_assert(offsetof(MiddleHighProcessData, rotation) == 0xB0, "rotation offset");
static_assert(offsetof(MiddleHighProcessData, unk1E8) == 0x1E8, "spin-lock offset");
static_assert(offsetof(MiddleHighProcessData, unk326) == 0x326, "head-tracking flag offset");

bool AIProcess::IsPickPocketed() const
{
    return middleHigh && middleHigh->pickPocketed;
}

InventoryEntryData* AIProcess::GetBothHands() const
{
    return middleHigh ? middleHigh->bothHands : nullptr;
}

InventoryEntryData* AIProcess::GetLeftHand() const
{
    return middleHigh ? middleHigh->leftHand : nullptr;
}

InventoryEntryData* AIProcess::GetRightHand() const
{
    return middleHigh ? middleHigh->rightHand : nullptr;
}

NiNode* AIProcess::GetWeaponBone() const
{
    return middleHigh ? middleHigh->weaponBone : nullptr;
}

void AIProcess::SetWeaponBone(NiNode* value)
{
    if (middleHigh) {
        middleHigh->weaponBone = value;
    }
}

bool AIProcess::Function7216a0() const
{
    return middleHigh && middleHigh->unk317;
}

bool AIProcess::Function7216c0() const
{
    return middleHigh && middleHigh->unk318;
}

BSAnimationGraphVariableCache* AIProcess::GetAnimationVariableCache() const
{
    return middleHigh ? middleHigh->animationVariableCache : nullptr;
}

void AIProcess::Function721a10()
{
    if (middleHigh) {
        middleHigh->unk1E8.Lock(0);
    }
}

TESPackage* AIProcess::Function721f30() const
{
    return middleHigh ? middleHigh->runOncePackage.package : nullptr;
}

TESPackage* AIProcess::Function721f50() const
{
    return middleHigh ? middleHigh->runOncePackage.package : nullptr;
}

void AIProcess::SetRunOnceProcedureIndex(std::int32_t value)
{
    if (middleHigh) {
        middleHigh->runOncePackage.currentProcedureIndex = value;
    }
}

std::int32_t AIProcess::GetRunOnceProcedureIndex() const
{
    return middleHigh ? middleHigh->runOncePackage.currentProcedureIndex : 0;
}

void AIProcess::AdvanceRunOnceProcedureIndex(std::int32_t value)
{
    if (middleHigh) {
        middleHigh->runOncePackage.currentProcedureIndex += value;
    }
}

ActorPackageData* AIProcess::GetRunOncePackageData() const
{
    return middleHigh ? middleHigh->runOncePackage.data : nullptr;
}

TESIdleForm* AIProcess::GetLastIdlePlayed() const
{
    return middleHigh ? middleHigh->lastIdlePlayed : nullptr;
}

float AIProcess::GetCurrentMovementSpeed() const
{
    return middleHigh ? middleHigh->currentMovementSpeed : 0.0f;
}

void AIProcess::SetCurrentMovementSpeed(float value)
{
    if (middleHigh) {
        middleHigh->currentMovementSpeed = value;
    }
}

void AIProcess::Function723390(float value)
{
    if (middleHigh) {
        middleHigh->unk2AC = value;
    }
}

const NiPoint3& AIProcess::GetRotation() const
{
    return middleHigh ? middleHigh->rotation : niPointZero;
}

float AIProcess::GetMoveDirectionRelativeToFacing()
{
    return middleHigh ? middleHigh->rotation.z : 0.0f;
}

void AIProcess::Function723580()
{
    if (middleHigh) {
        middleHigh->unk326 = false;
    }
}

void AIProcess::Function7245a0(std::uint8_t value)
{
    if (middleHigh) {
        middleHigh->unk310 = value;
    }
}

std::uint8_t AIProcess::Function7245c0() const
{
    return middleHigh ? middleHigh->unk310 : 0;
}

void AIProcess::Set3DUpdateFlag(RESET_3D_FLAGS flag)
{
    if (middleHigh) {
        middleHigh->update3DModel |= static_cast<std::uint8_t>(flag);
    }
}

void AIProcess::Clear3DUpdateFlags()
{
    if (middleHigh) {
        middleHigh->update3DModel = 0;
    }
}
