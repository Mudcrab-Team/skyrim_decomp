// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSStripParticleSystem, NiParticleSystem: CRASHLOGGER_PDB(59818@2026.10.24)
// unknown08, stripMode: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiParticleSystem
{
public:
    NiParticleSystem();
    virtual ~NiParticleSystem();

    std::uint8_t unknown08[0x148];
    std::uint8_t stripMode;  // 150
};
static_assert(offsetof(NiParticleSystem, stripMode) == 0x150, "stripMode offset");

class BSStripParticleSystem : public NiParticleSystem
{
public:
    BSStripParticleSystem();  // compared: 0xf9fc80
};
