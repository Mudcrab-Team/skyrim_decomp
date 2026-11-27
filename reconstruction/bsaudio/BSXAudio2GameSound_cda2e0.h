// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiPoint3: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3::x, NiPoint3::y, NiPoint3::z: CRASHLOGGER_PDB(59818@2026.10.24)
// BSAudioManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSAudioManager::Functioncca610, Functioncccf30: GUESS(low)
// AudioOrigin, AudioOrigin::unk00, AudioOrigin::position, gAudioOrigin, TestBit: GUESS(low)
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::soundType, BSXAudio2GameSound::flags, BSXAudio2GameSound::listenerDistance: CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Unk_00, BSXAudio2GameSound::Unk_01, BSXAudio2GameSound::Unk_02, BSXAudio2GameSound::Unk_03, BSXAudio2GameSound::Unk_04, BSXAudio2GameSound::Unk_05, BSXAudio2GameSound::Unk_06, BSXAudio2GameSound::Unk_07, BSXAudio2GameSound::Unk_08, BSXAudio2GameSound::Unk_09, BSXAudio2GameSound::Unk_0A, BSXAudio2GameSound::Unk_0B, BSXAudio2GameSound::Unk_0C, BSXAudio2GameSound::Unk_0D, BSXAudio2GameSound::Functioncda2e0, BSXAudio2GameSound::unk08, BSXAudio2GameSound::unk54, BSXAudio2GameSound::unk60, BSXAudio2GameSound::unk84, BSXAudio2GameSound::emitterPosition: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct AudioOrigin
{
    std::uint8_t unk00[0x18];
    NiPoint3 position;
};
static_assert(offsetof(AudioOrigin, position) == 0x18, "position offset");

extern AudioOrigin* gAudioOrigin;

class BSAudioManager
{
public:
    static BSAudioManager* Functioncca610();
};

const NiPoint3* Functioncccf30(BSAudioManager* a_manager);

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

class BSXAudio2GameSound
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

    void Functioncda2e0(const NiPoint3& a_pos);

    std::uint8_t unk08[0x48];
    std::uint32_t soundType;
    std::uint8_t unk54[0x08];
    std::uint32_t flags;
    std::uint8_t unk60[0x20];
    float listenerDistance;
    std::uint8_t unk84[0x104];
    NiPoint3 emitterPosition;
};
static_assert(offsetof(BSXAudio2GameSound, soundType) == 0x50, "soundType offset");
static_assert(offsetof(BSXAudio2GameSound, flags) == 0x5C, "flags offset");
static_assert(offsetof(BSXAudio2GameSound, listenerDistance) == 0x80, "listenerDistance offset");
static_assert(offsetof(BSXAudio2GameSound, emitterPosition) == 0x188, "emitterPosition offset");
