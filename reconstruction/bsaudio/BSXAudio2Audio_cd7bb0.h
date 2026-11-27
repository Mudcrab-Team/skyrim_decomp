// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2Audio: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2Audio::Func7_140BFB8F0: CRASHLOGGER_PDB(59818@2026.10.24)
// GetTickCount, g_reverbStartTime, g_reverbEndTime, g_reverbWetDryDefault, ReverbParams, ReverbParams::wetDryMix, ReverbParams::field04, ReverbParams::field08, ReverbParams::field0C, ReverbParams::field10, ReverbParams::field14, ReverbParams::field18, ReverbParams::field1C, ReverbParams::field20, ReverbParams::field24, ReverbParams::field28, ReverbParams::field2C, ReverbParams::field30, g_reverbParams, ReverbSource, ReverbSource::GetField04, ReverbSource::GetField08, ReverbSource::GetField10, ReverbSource::GetField14, ReverbSource::GetField18, ReverbSource::GetField1C, ReverbSource::GetField20, ReverbSource::GetField24, ReverbSource::GetField28, ReverbSource::GetField2C, ReverbSource::GetField30: GUESS(low)
#pragma once

#include <cstdint>

extern "C" __declspec(dllimport) std::uint32_t __stdcall GetTickCount();

extern std::uint32_t g_reverbEndTime;
extern std::uint32_t g_reverbStartTime;
extern const float g_reverbWetDryDefault;

struct ReverbParams
{
    float wetDryMix;
    std::uint32_t field04;
    std::uint32_t field08;
    float field0C;
    float field10;
    float field14;
    std::uint32_t field18;
    float field1C;
    std::uint32_t field20;
    float field24;
    float field28;
    float field2C;
    float field30;
};
static_assert(sizeof(ReverbParams) == 0x34, "ReverbParams size");

extern ReverbParams g_reverbParams;

class ReverbSource
{
public:
    virtual std::uint32_t GetField04();
    virtual std::uint32_t GetField08();
    virtual float GetField10();
    virtual float GetField14();
    virtual std::uint32_t GetField18();
    virtual float GetField1C();
    virtual std::uint32_t GetField20();
    virtual float GetField24();
    virtual float GetField28();
    virtual float GetField2C();
    virtual float GetField30();
};

class BSXAudio2Audio
{
public:
    void Func7_140BFB8F0(ReverbSource* a_source, std::uint32_t a_duration);
};
