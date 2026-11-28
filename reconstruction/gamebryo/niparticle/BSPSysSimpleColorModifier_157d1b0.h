// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSPSysSimpleColorModifier, BSPSysSimpleColorModifier::IsEqual, NiPSysModifier, NiObject: CRASHLOGGER_PDB(59818@2026.10.24)
// NiColorA, colors, fadeInPercent, fadeOutPercent, color1EndPercent, color1StartPercent, color2EndPercent, color2StartPercent, unknown08: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiObject
{
public:
    virtual ~NiObject();
    virtual bool IsEqual(NiObject* a_object);
};

class NiPSysModifier : public NiObject
{
public:
    bool IsEqual(NiObject* a_object) override;

    std::uint8_t unknown08[0x28];
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

struct NiColorA
{
    bool operator==(const NiColorA& a_rhs) const;

    float r;
    float g;
    float b;
    float a;
};
static_assert(sizeof(NiColorA) == 0x10, "NiColorA size");

class BSPSysSimpleColorModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* a_object) override;  // compared: 0x157d1b0

    NiColorA colors[3];        // 30
    float fadeInPercent;       // 60
    float fadeOutPercent;      // 64
    float color1EndPercent;    // 68
    float color1StartPercent;  // 6C
    float color2EndPercent;    // 70
    float color2StartPercent;  // 74
};
static_assert(offsetof(BSPSysSimpleColorModifier, colors) == 0x30, "colors offset");
static_assert(offsetof(BSPSysSimpleColorModifier, fadeInPercent) == 0x60, "fadeInPercent offset");
