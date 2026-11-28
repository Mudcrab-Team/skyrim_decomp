// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSWaterCollisionManager, bhkPlaceableWater: CRASHLOGGER_PDB(59818@2026.10.24)
// WaterTransform525f40, WaterPhysicsBody525f40, GetTransformHeight, QueryTransform, body: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct alignas(16) WaterTransform525f40
{
    float values[16];
};

class WaterPhysicsBody525f40
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void QueryTransform(WaterTransform525f40* a_out);
};

class BGSWaterCollisionManager
{
public:
    class bhkPlaceableWater
    {
    public:
        float GetTransformHeight();

        std::uint8_t unk00[0x40];
        WaterPhysicsBody525f40* body;
    };
};

static_assert(sizeof(WaterTransform525f40) == 0x40, "WaterTransform525f40 size");
static_assert(offsetof(BGSWaterCollisionManager::bhkPlaceableWater, body) == 0x40, "body offset");
