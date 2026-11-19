// Source exposure: mixed (pinned image listing and public names).
// Code origin: original reconstruction from the pinned image and community declarations; the earlier leaf bodies came from the project's bounded leaf template.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESPackage: EXE_RTTI
// Revert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESPackage::GetRefCount, TESPackage::GetObjectTypeName, TESPackage::~TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsPackageOwner: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// objectType, packFlags, unknown25, unknown26, unknown28, unknown2C, unknown50, unknown58, unknown68, unknown70, unknown78, unknown80, unknown88, unknown90, unknown98, unknownA0, unknownA8, unknownB0, unknownB8, unknownC0, unknownC8, unknownD0, PackageTarget::unknown01, PackageTarget::unknown02, PackageTarget::unknown14: GUESS(low); measured from the listings, names invented
// TESPackageData, PackageLocation, PackageTarget, BGSIdleCollection, TESCondition, data, packLoc, packTarg, idleCollection, packConditions, targType, target, value, head: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class TESPackageData : public BaseFormComponent
{
public:
    ~TESPackageData() override;
    // SaveGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 4, the call SaveGame makes through the vftable at +0x20
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);
};

class PackageLocation
{
public:
    virtual ~PackageLocation();
    // SaveGame: GUESS(low); call target 0x4a5300
    void SaveGame(BGSSaveFormBuffer* a_buf);
};

class BGSIdleCollection
{
public:
    virtual ~BGSIdleCollection();
};

class PackageTarget
{
public:
    ~PackageTarget();
    // SaveGame: GUESS(low); call target 0x4a6380
    void SaveGame(BGSSaveFormBuffer* a_buf);

    std::uint8_t targType;      // 00
    std::uint8_t unknown01;         // 01
    std::uint16_t unknown02;        // 02
    TESForm* target;            // 08
    std::int32_t value;         // 10
    std::uint32_t unknown14;        // 14
};
static_assert(sizeof(PackageTarget) == 0x18, "package target size");

class TESCondition
{
public:
    ~TESCondition();

    void* head;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "condition size");

class TESPackage : public TESForm
{
public:
    TESPackage();
    // IsPackageOwner: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
    virtual std::uint8_t IsPackageOwner() const;
    virtual std::uint32_t GetRefCount() const;
    virtual const char* GetObjectTypeName() const;
    virtual ~TESPackage();
    virtual void ClearData();
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);
    void Revert(BGSLoadFormBuffer* a_buf) override;  // compared: 0x49d7a0

private:
    // packFlags: GUESS(low); the dword at 0x20
    std::uint32_t packFlags;
    // objectType: GUESS(low); byte at 0x24, sign-extended and used as the table index
    std::int8_t objectType;
    // unknown25, unknown26, unknown28, unknown2C: GUESS(low); the bytes between the dword at 0x20 and the pointer at 0x30
    std::uint8_t unknown25;   // 25
    std::uint16_t unknown26;  // 26
    std::uint32_t unknown28;  // 28
    std::uint32_t unknown2C;  // 2C
    TESPackageData* data;               // 30
    PackageLocation* packLoc;           // 38
    PackageTarget* packTarg;            // 40
    BGSIdleCollection* idleCollection;  // 48
    // unknown50: GUESS(low); the schedule words, not read by these functions
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    TESCondition packConditions;        // 60
    // unknown68: GUESS(low); the rest of the package members, not read by these functions
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
    std::uint64_t unknown80;  // 80
    std::uint64_t unknown88;  // 88
    std::uint64_t unknown90;  // 90
    std::uint64_t unknown98;  // 98
    std::uint64_t unknownA0;  // A0
    std::uint64_t unknownA8;  // A8
    std::uint64_t unknownB0;  // B0
    std::uint64_t unknownB8;  // B8
    std::uint64_t unknownC0;  // C0
    std::uint64_t unknownC8;  // C8
    std::uint64_t unknownD0;  // D0
    // procedureType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); dword at 0xD8
    std::uint32_t procedureType;
    // refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); dword at 0xDC
    std::uint32_t refCount;
};
static_assert(sizeof(TESPackage) == 0xe0, "TESPackage size");
