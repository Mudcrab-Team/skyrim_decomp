// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::durationMilliseconds: CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Unk_00, BSXAudio2GameSound::Unk_01, BSXAudio2GameSound::Unk_02, BSXAudio2GameSound::Unk_03, BSXAudio2GameSound::Unk_04, BSXAudio2GameSound::Unk_05, BSXAudio2GameSound::Unk_06, BSXAudio2GameSound::Unk_07, BSXAudio2GameSound::Unk_08, BSXAudio2GameSound::Unk_09, BSXAudio2GameSound::Unk_0A, BSXAudio2GameSound::Unk_0B, BSXAudio2GameSound::Unk_0C, BSXAudio2GameSound::Unk_0D, BSXAudio2GameSound::Unk_0E, BSXAudio2GameSound::Unk_0F, BSXAudio2GameSound::Unk_10, BSXAudio2GameSound::Unk_11, BSXAudio2GameSound::Unk_12, BSXAudio2GameSound::Unk_13, BSXAudio2GameSound::Unk_14, BSXAudio2GameSound::Unk_15, BSXAudio2GameSound::Functioncd5a40, BSXAudio2GameSound::unk08, BSXAudio2GameSound::unk64, BSXAudio2GameSound::callback, BSXAudio2GameSound::unk98, BSXAudio2GameSound::callbackArg: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

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
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();

    void Functioncd5a40();

    std::uint8_t unk08[0x58];
    std::uint32_t durationMilliseconds;
    std::uint8_t unk64[0x2C];
    void (*callback)(void*, std::uint32_t);
    std::uint64_t unk98;
    void* callbackArg;
};
static_assert(offsetof(BSXAudio2GameSound, durationMilliseconds) == 0x60, "durationMilliseconds offset");
static_assert(offsetof(BSXAudio2GameSound, callback) == 0x90, "callback offset");
static_assert(offsetof(BSXAudio2GameSound, callbackArg) == 0xA0, "callbackArg offset");
