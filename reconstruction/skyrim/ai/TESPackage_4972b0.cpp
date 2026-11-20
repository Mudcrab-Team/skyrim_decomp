// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations from the listings using community package declarations.
// Adapted bodies: none
// 0x4972b0 TESPackage::UnlocksDoorsAtStart
// 0x4972e0 TESPackage::UnlocksDoorsAtEnd
// 0x497320 TESPackage::IsOncePerDay
// 0x497360 TESPackage::Function497360
// 0x4973d0 TESPackage::Function4973d0
// 0x4973e0 TESPackage::Function4973e0
// 0x497410 TESPackage::Function497410
// 0x497530 TESPackage::GetProcedureDataPointer
// 0x497680 TESPackage::GetDialogueDataPointer
// 0x497710 TESPackage::GetDialogueDataByte
// 0x4977a0 TESPackage::GetSandboxLocationValue
// 0x498840 TESPackage::GetInterruptOverrideType
// 0x498850 TESPackage::SetInterruptOverrideType
// 0x498860 TESPackage::GetMaxSpeed
// 0x498870 TESPackage::SetMaxSpeed
// 0x499c10 TESPackage::GetCustomPackageData
// 0x49b2f0 TESPackage::GetLocationValue
// 0x49b340 TESPackage::GetUseWeaponData
// 0x49b360 TESPackage::GetPatrolData
// 0x49b380 TESPackage::GetFollowData
// 0x49b3a0 TESPackage::GetGuardData
// 0x49b3c0 TESPackage::GetEscortData
// 0x49cf90 TESPackage::GetEscortValue
// 0x49d1c0 TESPackage::Function49d1c0
#include "TESPackage_4972b0.h"

// PrimaryData, DialogueData, WeaponData, EscortData, primary: STANDIN GUESS(low)
// first, second, value, value21: STANDIN GUESS(low)
class TESPackageData
{
public:
    virtual ~TESPackageData();
};

struct PrimaryData : TESPackageData
{
    void* primary;
};

struct EscortData : PrimaryData
{
    std::uint32_t value;
};

struct WeaponData : TESPackageData
{
    std::uint8_t padding08[8];
    void* value;
};

struct DialogueData : TESPackageData
{
    std::uint8_t padding08[8];
    void* first;
    void* second;
    std::uint8_t padding20;
    std::uint8_t value21;
};

bool TESPackage::UnlocksDoorsAtStart() const
{
    return (static_cast<std::uint8_t>(packData.packFlags) >> 6) & 1;
}

bool TESPackage::UnlocksDoorsAtEnd() const
{
    return (static_cast<std::uint8_t>(packData.packFlags) >> 7) & 1;
}

bool TESPackage::IsOncePerDay() const
{
    return (packData.packFlags >> 10) & 1;
}

bool TESPackage::Function497360() const
{
    return (packData.packFlags >> 11) & 1;
}

bool TESPackage::Function4973d0() const
{
    return (packData.packFlags >> 14) & 1;
}

void TESPackage::Function4973e0(bool enabled)
{
    if (enabled) {
        packData.packFlags |= 1u << 14;
    } else {
        packData.packFlags &= ~(1u << 14);
    }
}

bool TESPackage::Function497410() const
{
    return (packData.packFlags >> 15) & 1;
}

void* TESPackage::GetProcedureDataPointer() const
{
    if (data) {
        const auto type = packData.packType;
        if (type == PACKAGE_PROCEDURE_TYPE::kDialogue || type == PACKAGE_PROCEDURE_TYPE::kInGameDialogue) {
            return static_cast<DialogueData*>(data)->second;
        }
        if ((type >= PACKAGE_PROCEDURE_TYPE::kFollow && type <= PACKAGE_PROCEDURE_TYPE::kEat) || (type >= PACKAGE_PROCEDURE_TYPE::kUseItemAt && type <= PACKAGE_PROCEDURE_TYPE::kAmbush)) {
            return static_cast<PrimaryData*>(data)->primary;
        }
        if (type == PACKAGE_PROCEDURE_TYPE::kUseWeapon) {
            return static_cast<WeaponData*>(data)->value;
        }
    }
    return nullptr;
}

void* TESPackage::GetDialogueDataPointer() const
{
    void* result = nullptr;
    const auto type = packData.packType;
    if (type == PACKAGE_PROCEDURE_TYPE::kDialogue || type == PACKAGE_PROCEDURE_TYPE::kInGameDialogue) {
        const auto* dialogue = static_cast<const DialogueData*>(data);
        if (dialogue) {
            result = dialogue->first;
        }
    }
    return result;
}

std::uint8_t TESPackage::GetDialogueDataByte() const
{
    std::uint8_t result = 0;
    const auto type = packData.packType;
    if (type == PACKAGE_PROCEDURE_TYPE::kDialogue || type == PACKAGE_PROCEDURE_TYPE::kInGameDialogue) {
        const auto* dialogue = static_cast<const DialogueData*>(data);
        if (dialogue) {
            result = dialogue->value21;
        }
    }
    return result;
}

bool TESPackage::GetSandboxLocationValue(const void* context, float& result) const
{
    result = 0.0f;
    if (packData.packType == PACKAGE_PROCEDURE_TYPE::kSandbox) {
        result = static_cast<float>(Function49a4b0(context));
        return true;
    }
    return false;
}

std::int32_t TESPackage::GetInterruptOverrideType() const
{
    return packData.interruptOverrideType;
}

void TESPackage::SetInterruptOverrideType(std::int8_t type)
{
    packData.interruptOverrideType = type;
}

std::uint32_t TESPackage::GetMaxSpeed() const
{
    return packData.maxSpeed;
}

void TESPackage::SetMaxSpeed(std::uint8_t speed)
{
    packData.maxSpeed = speed;
}

TESPackageData* TESPackage::GetCustomPackageData() const
{
    if (packData.packType != PACKAGE_PROCEDURE_TYPE::kPackage && packData.packType != PACKAGE_PROCEDURE_TYPE::kPackageTemplate) {
        return nullptr;
    }
    return data;
}

std::uint32_t TESPackage::GetLocationValue(const void* context) const
{
    if (Function497580() == packLoc) {
        return Function49a4b0(context);
    }
    return Function49e750();
}

TESPackageData* TESPackage::GetUseWeaponData() const
{
    return packData.packType == PACKAGE_PROCEDURE_TYPE::kUseWeapon ? data : nullptr;
}

TESPackageData* TESPackage::GetPatrolData() const
{
    return packData.packType == PACKAGE_PROCEDURE_TYPE::kPatrol ? data : nullptr;
}

TESPackageData* TESPackage::GetFollowData() const
{
    return packData.packType == PACKAGE_PROCEDURE_TYPE::kFollow ? data : nullptr;
}

TESPackageData* TESPackage::GetGuardData() const
{
    return packData.packType == PACKAGE_PROCEDURE_TYPE::kGuard ? data : nullptr;
}

TESPackageData* TESPackage::GetEscortData() const
{
    return packData.packType == PACKAGE_PROCEDURE_TYPE::kEscort ? data : nullptr;
}

std::uint32_t TESPackage::GetEscortValue() const
{
    if (packData.packType != PACKAGE_PROCEDURE_TYPE::kEscort) {
        return 256;
    }
    return static_cast<EscortData*>(data)->value;
}

bool TESPackage::Function49d1c0() const
{
    using Type = PACKAGE_PROCEDURE_TYPE;
    return procedureType == static_cast<int>(Type::kEscort) ||
           procedureType == static_cast<int>(Type::kEat) ||
           procedureType == static_cast<int>(Type::kSleep) ||
           procedureType == static_cast<int>(Type::kWander) ||
           procedureType == static_cast<int>(Type::kSpectator) ||
           procedureType == 46 || procedureType == 48 || procedureType == 49;
}
