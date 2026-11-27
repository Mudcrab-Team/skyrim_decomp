// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sky, Sky::FinishLoadGame, Sky::currentWeather, Sky::lastWeather, Sky::clouds, Sky::mode, Sky::flags, Sky::currentReferenceEffect, Sky::lastReferenceEffect, Sky::Update, BGSLoadFormBuffer, ReferenceEffect, Clouds, TESWeather: CRASHLOGGER_PDB(59818@2026.10.24)
// ReferenceEffect::FinishLoadGame, Clouds::forceUpdate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReferenceEffectManager, g_referenceEffectManager, Function784ad0, Function40cdc0, Unk_00..Unk_2E, unk00, unk58, unk90, unk1C0, unk1E0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BGSLoadFormBuffer;
class TESWeather;

class ReferenceEffect
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
    virtual void FinishLoadGame(BGSLoadFormBuffer* buf);
};

class Clouds
{
public:
    void Function40cdc0(TESWeather* weather);

    std::uint8_t unk00[0x512];
    bool forceUpdate;     // 512
};
static_assert(offsetof(Clouds, forceUpdate) == 0x512, "Clouds forceUpdate offset");

class ReferenceEffectManager
{
public:
    void Function784ad0(ReferenceEffect* effect);
};

extern ReferenceEffectManager* g_referenceEffectManager;

class Sky
{
public:
    void FinishLoadGame(BGSLoadFormBuffer* buf);  // compared: 0x4181d0
    void Update(float unk);

    std::uint8_t unk00[0x48];
    TESWeather* currentWeather;               // 48
    TESWeather* lastWeather;                  // 50
    std::uint8_t unk58[0x88 - 0x58];
    Clouds* clouds;                           // 88
    std::uint8_t unk90[0x1bc - 0x90];
    std::uint32_t mode;                       // 1BC
    std::uint8_t unk1C0[0x1dc - 0x1c0];
    std::uint32_t flags;                      // 1DC
    std::uint8_t unk1E0[0x268 - 0x1e0];
    ReferenceEffect* currentReferenceEffect;  // 268
    ReferenceEffect* lastReferenceEffect;     // 270
};
static_assert(offsetof(Sky, currentWeather) == 0x48, "Sky currentWeather offset");
static_assert(offsetof(Sky, lastWeather) == 0x50, "Sky lastWeather offset");
static_assert(offsetof(Sky, clouds) == 0x88, "Sky clouds offset");
static_assert(offsetof(Sky, mode) == 0x1bc, "Sky mode offset");
static_assert(offsetof(Sky, flags) == 0x1dc, "Sky flags offset");
static_assert(offsetof(Sky, currentReferenceEffect) == 0x268, "Sky currentReferenceEffect offset");
static_assert(offsetof(Sky, lastReferenceEffect) == 0x270, "Sky lastReferenceEffect offset");
