// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSISoundOutputModel: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSISoundOutputModel::Unk_00, BSISoundOutputModel::Unk_01, BSISoundOutputModel::Unk_02, BSISoundOutputModel::Unk_03, BSISoundOutputModel::Unk_04: GUESS(low)
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::soundType, BSXAudio2GameSound::outputModel: CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncd5880, BSXAudio2GameSound::unk00, BSXAudio2GameSound::unk54: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSISoundOutputModel
{
public:
    virtual void Unk_00();
    virtual bool Unk_01();
    virtual bool Unk_02();
    virtual void Unk_03();
    virtual bool Unk_04();
};

class BSXAudio2GameSound
{
public:
    bool Functioncd5880();

    std::uint8_t unk00[0x50];
    std::uint32_t soundType;
    std::uint8_t unk54[0x64];
    BSISoundOutputModel* outputModel;
};
static_assert(offsetof(BSXAudio2GameSound, soundType) == 0x50, "soundType offset");
static_assert(offsetof(BSXAudio2GameSound, outputModel) == 0xB8, "outputModel offset");
