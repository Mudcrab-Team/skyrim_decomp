// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageDataObjectList.cpp:240
// BGSPackageDataObjectList::Copy: SIBLING(fo4-private@1b765c70, author-permission); the Skyrim slot is Assign
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IPackageData, IPackageData::Assign: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN OBSERVED; NG declares Assign with a non-const parameter
// BGSPackageDataObjectList: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; the listing reads the copied array and radius through a second base subobject at +0x8 of the cast result
// PackageObjectArray, PackageObjectData, PackageObjectData::Assign, PackageObjectData::array, PackageObjectData::radius, PackageObjectArray::CopyTo, BGSPackageDataObjectList::head: GUESS(low)
#pragma once

class IPackageData
{
public:
    virtual ~IPackageData();
    virtual void Assign(const IPackageData* a_other);  // 03
};

class PackageObjectArray
{
public:
    void CopyTo(PackageObjectArray& a_dst);

    void* unknown00[3];  // 00
};
static_assert(sizeof(PackageObjectArray) == 0x18, "PackageObjectArray size");

class PackageObjectHead
{
public:
    virtual ~PackageObjectHead();
};

class PackageObjectData : public IPackageData
{
public:
    void Assign(const IPackageData* a_other) override;

    void* unknown08;                // 08
    void* unknown10;                // 10
    PackageObjectArray array;       // 18
    float radius;                   // 30
    unsigned int unknown34;         // 34
};

class BGSPackageDataObjectList : public PackageObjectHead, public PackageObjectData
{
};
