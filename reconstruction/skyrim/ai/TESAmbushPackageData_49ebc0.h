// Source exposure: mixed (community headers; the pinned image listing).
// TESAmbushPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// PackageDataPayload, TESAmbushPackageData::payload: GUESS(low)
#pragma once

class TESPackageData
{
public:
    virtual ~TESPackageData() {}
};

class PackageDataPayload
{
public:
    virtual ~PackageDataPayload() {}
};

class TESAmbushPackageData : public TESPackageData
{
public:
    ~TESAmbushPackageData() override;

    PackageDataPayload* payload;  // 08
};
static_assert(sizeof(TESAmbushPackageData) == 0x10, "TESAmbushPackageData size");
