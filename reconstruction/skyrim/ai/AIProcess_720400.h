// Source exposure: mixed (pinned image listings, project AIProcess, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations follow the CommonLibSSE-NG AIProcess layout.
// AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorPackageData, TESPackage, NiNode, InventoryEntryData, TESIdleForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSAnimationGraphVariableCache, MiddleHighProcessData, NiPoint3, AIProcess::middleHigh: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess::Set3DUpdateFlag, RESET_3D_FLAGS: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorProcess::GetBothHands: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// padding: STANDIN GUESS(low)
// IsPickPocketed, GetLeftHand, GetRightHand, GetWeaponBone, SetWeaponBone: GUESS(low)
// Function7216a0, Function7216c0, GetAnimationVariableCache, Function721a10: GUESS(low)
// Function721f30, Function721f50, SetRunOnceProcedureIndex, GetRunOnceProcedureIndex, AdvanceRunOnceProcedureIndex: GUESS(low)
// GetRunOncePackageData, GetLastIdlePlayed, GetCurrentMovementSpeed, SetCurrentMovementSpeed: GUESS(low)
// Function723390, GetRotation, GetMoveDirectionRelativeToFacing, Function723580, Function7245a0, Function7245c0, Clear3DUpdateFlags: GUESS(low)
#pragma once

#include <cstdint>

class ActorPackageData;
struct BSAnimationGraphVariableCache;
class InventoryEntryData;
struct MiddleHighProcessData;
class NiNode;
class NiPoint3;
class TESIdleForm;
class TESPackage;
enum class RESET_3D_FLAGS;

class AIProcess
{
public:
    bool IsPickPocketed() const;
    InventoryEntryData* GetBothHands() const;
    InventoryEntryData* GetLeftHand() const;
    InventoryEntryData* GetRightHand() const;
    NiNode* GetWeaponBone() const;
    void SetWeaponBone(NiNode* value);
    bool Function7216a0() const;
    bool Function7216c0() const;
    BSAnimationGraphVariableCache* GetAnimationVariableCache() const;
    void Function721a10();
    TESPackage* Function721f30() const;
    TESPackage* Function721f50() const;
    void SetRunOnceProcedureIndex(std::int32_t value);
    std::int32_t GetRunOnceProcedureIndex() const;
    void AdvanceRunOnceProcedureIndex(std::int32_t value);
    ActorPackageData* GetRunOncePackageData() const;
    TESIdleForm* GetLastIdlePlayed() const;
    float GetCurrentMovementSpeed() const;
    void SetCurrentMovementSpeed(float value);
    void Function723390(float value);
    const NiPoint3& GetRotation() const;
    float GetMoveDirectionRelativeToFacing();
    void Function723580();
    void Function7245a0(std::uint8_t value);
    std::uint8_t Function7245c0() const;
    void Set3DUpdateFlag(RESET_3D_FLAGS flag);
    void Clear3DUpdateFlags();

private:
    std::uint8_t padding[0x8];
    MiddleHighProcessData* middleHigh;
};
