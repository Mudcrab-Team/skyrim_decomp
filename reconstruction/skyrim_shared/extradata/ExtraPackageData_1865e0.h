// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSExtraData, ExtraPackageData, ExtraPackageData::~ExtraPackageData: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// ExtraPackageData::packageData: GUESS(low); the FO4 layout names this slot pActorPackageData
#pragma once

#include <cstdint>
#include <cstddef>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    std::uint8_t unk08[0x8];
};

struct ActorPackageData
{
    virtual ~ActorPackageData() {}
};

class ExtraPackageData : public BSExtraData
{
public:
    ~ExtraPackageData() override;  // compared: 0x1865e0

    ActorPackageData* packageData;  // 0x10
    std::uint64_t unk18;
};
static_assert(sizeof(ExtraPackageData) == 32, "ExtraPackageData size");
