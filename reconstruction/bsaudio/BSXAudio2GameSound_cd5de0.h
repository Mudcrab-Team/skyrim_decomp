// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSISoundCategory: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSISoundCategory::Unk_00, BSISoundCategory::Unk_01: GUESS(low)
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::category: CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncd5de0, BSXAudio2GameSound::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSISoundCategory
{
public:
    virtual void Unk_00();
    virtual bool Unk_01();
};

class BSXAudio2GameSound
{
public:
    bool Functioncd5de0();

    std::uint8_t unk00[0xB0];
    BSISoundCategory* category;
};
static_assert(offsetof(BSXAudio2GameSound, category) == 0xB0, "category offset");
