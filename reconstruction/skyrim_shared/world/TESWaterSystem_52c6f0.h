// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESWaterSystem, WaterObject, WaterShape, WaterSetup, WaterState, WaterType, g_waterType, unk10, unk30, unk128, unk18, unk10Field: GUESS(low)
// GetWorldRootCamera, ApplyCamera: GUESS(low); Main::WorldRootCamera and NiNode::Function224640 are the CrashLogger names of the callees
// TESWaterSystem::Function52c6f0: CRASHLOGGER_PDB(59818@2026.10.24); size only
#pragma once

#include <cstdint>
#include <cstddef>

struct WaterType;
extern WaterType g_waterType;

struct WaterState
{
    std::uint8_t pad00[0x10];
    std::int32_t unk10Field;  // 0x10
};

struct WaterSetup
{
    std::uint8_t pad00[0x18];
    WaterState* unk18;  // 0x18
};

class WaterShape
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual WaterType* unk02();  // slot 2

    std::uint8_t pad08[0x128 - 0x08];
    WaterSetup* unk128;  // 0x128
};

class WaterObject
{
public:
    bool ApplyCamera(void* a_camera);  // CrashLogger name NiNode::Function224640

    std::uint8_t pad00[0x30];
    WaterShape* unk30;  // 0x30
};

void* GetWorldRootCamera();  // CrashLogger name Main::WorldRootCamera

class TESWaterSystem
{
public:
    bool Function52c6f0(WaterObject* a_object);  // compared: 0x52c6f0
};
