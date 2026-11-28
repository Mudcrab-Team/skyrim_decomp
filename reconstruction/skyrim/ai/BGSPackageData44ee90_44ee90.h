// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// IPackageData, IsNotEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSPackageData44ee90, PackageDataPrimary44ee90, PackageDataSecondary44ee90, unk08, unk10, firstBits, secondValue: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class IPackageData
{
public:
    virtual ~IPackageData();
    virtual bool IsNotEqual(IPackageData* other) const = 0;
};

class BGSPackageData44ee90 : public IPackageData
{
public:
    bool IsNotEqual(IPackageData* other) const override;

    std::uint64_t unk08;  // 08
    std::uint32_t unk10;  // 10
};
static_assert(sizeof(BGSPackageData44ee90) == 0x18, "BGSPackageData44ee90 size");

class PackageDataPrimary44ee90 : public IPackageData
{
public:
    std::uint64_t unk08;      // 08
    std::uint64_t firstBits;  // 10
};
static_assert(sizeof(PackageDataPrimary44ee90) == 0x18, "PackageDataPrimary44ee90 size");

class PackageDataSecondary44ee90 : public PackageDataPrimary44ee90
{
public:
    std::uint32_t secondValue;  // 18
};
static_assert(sizeof(PackageDataSecondary44ee90) == 0x20, "PackageDataSecondary44ee90 size");
