// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// StreamBase: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// StreamBase::Unk_00, StreamBase::Unk_01, StreamBase::Unk_02, StreamBase::Unk_03, StreamBase::Unk_04, StreamBase::Unk_05, StreamBase::Unk_06, StreamBase::Unk_07, StreamBase::Unk_08, StreamBase::Unk_09, StreamBase::Unk_0A: GUESS(low)
// BSXAudio2DataSrc: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2DataSrc::stream: CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2DataSrc::unk00: GUESS(low)
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::src: CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncd94c0, BSXAudio2GameSound::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class StreamBase
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
    virtual std::uint32_t Unk_0A(std::uint32_t* a_out, std::uint32_t a_arg);
};

class BSXAudio2DataSrc
{
public:
    std::uint8_t unk00[0x10];
    StreamBase* stream;
};
static_assert(offsetof(BSXAudio2DataSrc, stream) == 0x10, "stream offset");

class BSXAudio2GameSound
{
public:
    bool Functioncd94c0();

    std::uint8_t unk00[0xD0];
    BSXAudio2DataSrc* src;
};
static_assert(offsetof(BSXAudio2GameSound, src) == 0xD0, "src offset");
