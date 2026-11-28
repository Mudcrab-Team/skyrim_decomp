// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// IPackageData, Assign: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSPackageData44ee50, PackageDataSource44ee50, unk08, value, sourceValue: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class IPackageData
{
public:
    virtual ~IPackageData();
    virtual void Assign(IPackageData* source) = 0;
};

class BGSPackageData44ee50 : public IPackageData
{
public:
    void Assign(IPackageData* source) override;

    std::uint64_t unk08;  // 08
    std::uint32_t value;  // 10
};
static_assert(sizeof(BGSPackageData44ee50) == 0x18, "BGSPackageData44ee50 size");

class PackageDataSource44ee50 : public BGSPackageData44ee50
{
public:
    std::uint32_t sourceValue;  // 18
};
static_assert(sizeof(PackageDataSource44ee50) == 0x20, "PackageDataSource44ee50 size");
