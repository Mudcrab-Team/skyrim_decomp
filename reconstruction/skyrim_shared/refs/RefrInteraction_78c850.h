// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// RefrInteraction, RefrInteraction::FinishLoadGame, RefrInteraction::synced: CRASHLOGGER_PDB(59818@2026.10.24)
// Unk_01, Unk_02, Unk_03, Unk_04, Unk_05, Unk_06, Unk_07, Unk_08, Unk_09, Unk_0A, Unk_0B, Unk_0C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class RefrInteraction
{
public:
    virtual ~RefrInteraction();
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

    void FinishLoadGame();

    std::uint8_t unk08[0x10];
    bool synced;
};

static_assert(offsetof(RefrInteraction, synced) == 0x18, "synced offset");
