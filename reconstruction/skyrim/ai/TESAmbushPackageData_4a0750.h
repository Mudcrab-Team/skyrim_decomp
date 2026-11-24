// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// TESAmbushPackageData: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); sibling name, identity with this function unproven
// TESAmbushPackageData::Compare_0067af50: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); sibling name, identity with this function unproven
#pragma once

struct AF50Location;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESForm;
struct TESPackageData;
struct TESPatrolPackageData;

class TESPackageData
{
public:
    TESPackageData();
    virtual ~TESPackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* item);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    void Save(int);
};

class TESAmbushPackageData : public TESPackageData
{
public:
    virtual ~TESAmbushPackageData();

    bool vf02(TESPackageData* pkOtherData);

    void* Destroy(unsigned int flags);
    void SaveWithTag();
    void SetLocationFromPackage(int apCopy);
    bool Compare_0067af50(TESPackageData* apCompare);

    AF50Location* pAmbushLocation; // src: XBOX_RETAIL_PDB +0x4 (old: m_pkLocation)
};



class AF50Location
{
  public:
    bool PackageLocation_Compare(AF50Location* apCompare);
};
