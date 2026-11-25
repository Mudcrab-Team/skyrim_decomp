// Source exposure: mixed (pinned image, community declarations and CrashLogger names).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original reconstruction; minimal declarations from the named sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSXAudio2Audio: CRASHLOGGER_PDB(59818@2026.10.24)
// ReleaseGameSound: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSGameSound, Unk_00, Unk_02, Unk_03, Unk_04, Unk_05, Unk_06, Unk_07, Unk_08, Unk_09, Unk_0A, Unk_0B, Unk_0C, Unk_0D, Unk_0E, Unk_0F, Unk_10, Unk_11, Unk_12: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// audioMemoryContext: GUESS(low); current thread's allocation context.
// 0xcd7a60 BSXAudio2Audio::ReleaseGameSound
#pragma once
#include <cstdint>

class BSGameSound {
public:
    virtual void Unk_00();
    virtual ~BSGameSound();
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
};

extern __declspec(thread) std::uint32_t audioMemoryContext;

class BSXAudio2Audio {
public:
    void ReleaseGameSound(BSGameSound* sound);
};
