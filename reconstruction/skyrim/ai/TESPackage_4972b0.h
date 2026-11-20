// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial TESPackage layout adapted from CommonLibSSE-NG. Method signatures are inferred.
// UnlocksDoorsAtStart, UnlocksDoorsAtEnd, IsOncePerDay, Function497360, Function4973d0: GUESS(low)
// Function497410, Function4973e0, GetProcedureDataPointer, GetDialogueDataPointer, GetDialogueDataByte: GUESS(low)
// GetSandboxLocationValue, GetInterruptOverrideType, SetInterruptOverrideType, GetMaxSpeed: GUESS(low)
// SetMaxSpeed, GetCustomPackageData, GetLocationValue, GetUseWeaponData, GetPatrolData: GUESS(low)
// GetFollowData, GetGuardData, GetEscortData, GetEscortValue, Function49d1c0: GUESS(low)
// TESPackage, TESPackageData, PackageLocation, RE::PACKAGE_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// packData, PACKAGE_DATA::packFlags, PACKAGE_DATA::packType, PACKAGE_DATA::interruptOverrideType, PACKAGE_DATA::maxSpeed: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// data, packLoc, procedureType, PACKAGE_PROCEDURE_TYPE::kFollow: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PACKAGE_PROCEDURE_TYPE::kEscort, PACKAGE_PROCEDURE_TYPE::kEat, PACKAGE_PROCEDURE_TYPE::kSleep, PACKAGE_PROCEDURE_TYPE::kWander, PACKAGE_PROCEDURE_TYPE::kUseItemAt: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PACKAGE_PROCEDURE_TYPE::kAmbush, PACKAGE_PROCEDURE_TYPE::kSandbox, PACKAGE_PROCEDURE_TYPE::kPatrol, PACKAGE_PROCEDURE_TYPE::kGuard, PACKAGE_PROCEDURE_TYPE::kDialogue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PACKAGE_PROCEDURE_TYPE::kUseWeapon, PACKAGE_PROCEDURE_TYPE::kPackage, PACKAGE_PROCEDURE_TYPE::kPackageTemplate, PACKAGE_PROCEDURE_TYPE::kSpectator, PACKAGE_PROCEDURE_TYPE::kInGameDialogue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function497580, Function49a4b0, Function49e750, padding: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class TESPackageData;
class PackageLocation;

enum class PACKAGE_PROCEDURE_TYPE : std::uint8_t {
    kFollow = 1, kEscort = 2, kEat = 3, kSleep = 4, kWander = 5,
    kUseItemAt = 8, kAmbush = 9, kSandbox = 12, kPatrol = 13, kGuard = 14,
    kDialogue = 15, kUseWeapon = 16, kPackage = 18, kPackageTemplate = 19,
    kSpectator = 24, kInGameDialogue = 28
};

struct PACKAGE_DATA
{
    std::uint32_t packFlags;
    PACKAGE_PROCEDURE_TYPE packType;
    std::int8_t interruptOverrideType;
    std::uint8_t maxSpeed;
    std::uint8_t padding07[5];
};

class TESPackage
{
public:
    bool UnlocksDoorsAtStart() const;
    bool UnlocksDoorsAtEnd() const;
    bool IsOncePerDay() const;
    bool Function497360() const;
    bool Function4973d0() const;
    void Function4973e0(bool enabled);
    bool Function497410() const;
    void* GetProcedureDataPointer() const;
    void* GetDialogueDataPointer() const;
    std::uint8_t GetDialogueDataByte() const;
    bool GetSandboxLocationValue(const void* context, float& result) const;
    std::int32_t GetInterruptOverrideType() const;
    void SetInterruptOverrideType(std::int8_t type);
    std::uint32_t GetMaxSpeed() const;
    void SetMaxSpeed(std::uint8_t speed);
    TESPackageData* GetCustomPackageData() const;
    std::uint32_t GetLocationValue(const void* context) const;
    TESPackageData* GetUseWeaponData() const;
    TESPackageData* GetPatrolData() const;
    TESPackageData* GetFollowData() const;
    TESPackageData* GetGuardData() const;
    TESPackageData* GetEscortData() const;
    std::uint32_t GetEscortValue() const;
    bool Function49d1c0() const;

private:
    PackageLocation* Function497580() const;
    std::uint32_t Function49a4b0(const void* context) const;
    std::uint32_t Function49e750() const;

    std::uint8_t padding00[0x20];
    PACKAGE_DATA packData;
    std::uint8_t padding2C[4];
    TESPackageData* data;
    PackageLocation* packLoc;
    std::uint8_t padding40[0x98];
    std::int32_t procedureType;
};
