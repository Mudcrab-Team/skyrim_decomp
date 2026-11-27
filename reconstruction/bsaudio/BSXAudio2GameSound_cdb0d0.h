// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// VoiceState, VoiceState::currentBufferContext, VoiceState::buffersQueued, VoiceState::samplesPlayed: GUESS(low)
// IXAudio2SourceVoice: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// IXAudio2SourceVoice::Unk_00, IXAudio2SourceVoice::Unk_01, IXAudio2SourceVoice::Unk_02, IXAudio2SourceVoice::Unk_03, IXAudio2SourceVoice::Unk_04, IXAudio2SourceVoice::Unk_05, IXAudio2SourceVoice::Unk_06, IXAudio2SourceVoice::Unk_07, IXAudio2SourceVoice::Unk_08, IXAudio2SourceVoice::Unk_09, IXAudio2SourceVoice::Unk_0A, IXAudio2SourceVoice::Unk_0B, IXAudio2SourceVoice::Unk_0C, IXAudio2SourceVoice::Unk_0D, IXAudio2SourceVoice::Unk_0E, IXAudio2SourceVoice::Unk_0F, IXAudio2SourceVoice::Unk_10, IXAudio2SourceVoice::Unk_11, IXAudio2SourceVoice::Unk_12, IXAudio2SourceVoice::Stop, IXAudio2SourceVoice::Unk_14, IXAudio2SourceVoice::Unk_15, IXAudio2SourceVoice::Unk_16, IXAudio2SourceVoice::Unk_17, IXAudio2SourceVoice::Unk_18, IXAudio2SourceVoice::GetState: GUESS(low)
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::samplesPlayed, BSXAudio2GameSound::sourceVoice: CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncdb0d0, BSXAudio2GameSound::unk00, BSXAudio2GameSound::unk124: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

#pragma pack(push, 1)
struct VoiceState
{
    void* currentBufferContext;
    std::uint32_t buffersQueued;
    std::uint64_t samplesPlayed;
};
#pragma pack(pop)
static_assert(offsetof(VoiceState, samplesPlayed) == 0x0C, "samplesPlayed offset");
static_assert(sizeof(VoiceState) == 0x14, "VoiceState size");

class IXAudio2SourceVoice
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
    virtual std::int32_t Stop(std::uint32_t a_flags, std::uint32_t a_operationSet);
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void GetState(VoiceState* a_state);
};

class BSXAudio2GameSound
{
public:
    std::int32_t Functioncdb0d0();

    std::uint8_t unk00[0x120];
    std::uint32_t samplesPlayed;
    std::uint32_t unk124;
    IXAudio2SourceVoice* sourceVoice;
};
static_assert(offsetof(BSXAudio2GameSound, samplesPlayed) == 0x120, "samplesPlayed offset");
static_assert(offsetof(BSXAudio2GameSound, sourceVoice) == 0x128, "sourceVoice offset");
