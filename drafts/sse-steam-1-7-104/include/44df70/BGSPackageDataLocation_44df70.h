// Exposure detail: (local binary analysis and labelled declarations).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPackageDataLocation, PackageLocation, AIWorldLocationContext, TESObjectREFR, pointer, GetAsPackageLocation, AllocateLocation: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsRefAtLocation: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// unk00: GUESS(low); unaccessed prefix.

#pragma once
#include <cstddef>
#include <cstdint>

class AIWorldLocationContext;
class TESObjectREFR;
class PackageLocation
{
public:
    virtual ~PackageLocation();
    virtual const void* AllocateLocation(AIWorldLocationContext*);
    virtual PackageLocation* GetAsPackageLocation();
    virtual bool IsRefAtLocation(AIWorldLocationContext&, TESObjectREFR*);
};

class BGSPackageDataLocation
{
public:
    bool IsRefAtLocation(AIWorldLocationContext& context, TESObjectREFR* ref) const;
    std::uint8_t unk00[0x18];
    PackageLocation* pointer;
};
static_assert(offsetof(BGSPackageDataLocation, pointer) == 0x18, "location pointer offset");
