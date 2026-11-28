// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TestBit, treated as adapted: shaped like TestBit in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// TESRegionGrassObject2544b0, TESRegionGrassObject2544b0::ValidObject: CRASHLOGGER_PDB(59818@2026.10.24)
// ModelData2544b0, GrassForm2544b0, HasModel, flags, model: GUESS(low)
#pragma once

#include <cstdint>

class ModelData2544b0
{
public:
    std::uint32_t HasModel() const;
};

struct GrassForm2544b0
{
    std::uint8_t unk00[0x10];  // 00
    std::uint32_t flags;       // 10
    std::uint8_t unk14[0x24];  // 14
    ModelData2544b0 model;     // 38
};

class TESRegionGrassObject2544b0
{
public:
    static std::uint32_t ValidObject(GrassForm2544b0* form);
};
