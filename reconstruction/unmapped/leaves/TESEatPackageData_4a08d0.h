// Source exposure: mixed (community headers; the pinned image listing).
// TESEatPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// PackageDataPayload, TESEatPackageData::payload: GUESS(low)
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

class TESEatPackageData : public TESPackageData
{
public:
    ~TESEatPackageData() override;

    PackageDataPayload* payload;  // 08
};
static_assert(sizeof(TESEatPackageData) == 0x10, "TESEatPackageData size");
