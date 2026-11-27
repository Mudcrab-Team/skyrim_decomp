// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESWaterSystem::ResetWaterDisplacementSimulation: CRASHLOGGER_PDB(59818@2026.10.24); name only
// TESWaterSystem, WaterDisplacementSimulation, WaterDisplacementSimulation::Function52f8d0, unkD4, simulation: STANDIN GUESS(low); the callee at 0x52f8d0 and the members are read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class WaterDisplacementSimulation
{
public:
    void Function52f8d0();  // callee at 0x52f8d0, not compared here
    std::uint8_t unk00[0x10];
};

class TESWaterSystem
{
public:
    void ResetWaterDisplacementSimulation();  // compared: 0x52af40

    std::uint8_t unk00[0xd4];
    float unkD4;                           // D4
    WaterDisplacementSimulation simulation;  // D8
};
static_assert(offsetof(TESWaterSystem, simulation) == 0xd8, "layout");
