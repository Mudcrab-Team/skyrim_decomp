// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2Audio: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2Audio::Func7_140BFB8F0: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xcd7bb0 BSXAudio2Audio::Func7_140BFB8F0
#include "BSXAudio2Audio_cd7bb0.h"

// Record transition timestamps and populate global reverb parameters from the source interface.
void BSXAudio2Audio::Func7_140BFB8F0(ReverbSource* a_source, std::uint32_t a_duration)
{
    const std::uint32_t now = GetTickCount();
    g_reverbStartTime = now;
    g_reverbEndTime = now + a_duration;
    g_reverbParams.wetDryMix = g_reverbWetDryDefault;
    g_reverbParams.field0C = 0.0f;
    g_reverbParams.field04 = a_source->GetField04();
    g_reverbParams.field08 = a_source->GetField08();
    g_reverbParams.field10 = a_source->GetField10();
    g_reverbParams.field14 = a_source->GetField14();
    g_reverbParams.field18 = a_source->GetField18();
    g_reverbParams.field1C = a_source->GetField1C();
    g_reverbParams.field20 = a_source->GetField20();
    g_reverbParams.field24 = a_source->GetField24();
    g_reverbParams.field2C = a_source->GetField2C();
    g_reverbParams.field28 = a_source->GetField28();
    g_reverbParams.field30 = a_source->GetField30();
}
