// Source exposure: mixed (community headers; CrashLogger layout; the pinned image listing).
// BGSPackageDataList: SIBLING(fo4-private@1b765c70, author-permission) CRASHLOGGER_PDB(59818@2026.10.24)
// BGSPackageDataList::InitItems, BGSPackageDataList::GetByUID, BGSPackageDataList::GetUIDForData, BGSPackageDataList::FindData: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IPackageData, IPackageData::InitPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN OBSERVED; NG declares InitPackage without a parameter, the listing passes the owner form
// BGSPackageDataList::data, BGSPackageDataList::uids, BGSPackageDataList::dataSize, BGSPackageDataList::nextUID: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class TESForm;

class IPackageData
{
public:
    virtual ~IPackageData();
    virtual void InitPackage(TESForm* a_owner);  // 01
};

class BGSPackageDataList
{
public:
    void InitItems(TESForm* a_owner);
    IPackageData* GetByUID(unsigned char a_uid) const;
    unsigned char GetUIDForData(const IPackageData* a_data) const;
    unsigned int FindData(const IPackageData* a_data) const;

    IPackageData** data;      // 00
    unsigned char* uids;      // 08
    unsigned short dataSize;  // 10
    unsigned char nextUID;    // 12
    unsigned char pad13;      // 13
    unsigned int pad14;       // 14
};
static_assert(sizeof(BGSPackageDataList) == 0x18, "BGSPackageDataList size");
