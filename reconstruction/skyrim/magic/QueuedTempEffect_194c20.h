// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// QueuedTempEffect, sub_140146F20: CRASHLOGGER_PDB(59818@2026.10.24)
// TempEffectTarget, FinishEffect, unk00, state, unk10, target, Unk_01..Unk_24: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class TempEffectTarget
{
public:
    virtual ~TempEffectTarget();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B(); virtual void Unk_0C();
    virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F(); virtual void Unk_10();
    virtual void Unk_11(); virtual void Unk_12(); virtual void Unk_13(); virtual void Unk_14();
    virtual void Unk_15(); virtual void Unk_16(); virtual void Unk_17(); virtual void Unk_18();
    virtual void Unk_19(); virtual void Unk_1A(); virtual void Unk_1B(); virtual void Unk_1C();
    virtual void Unk_1D(); virtual void Unk_1E(); virtual void Unk_1F(); virtual void Unk_20();
    virtual void Unk_21(); virtual void Unk_22(); virtual void Unk_23(); virtual void Unk_24();
    virtual void FinishEffect();  // 128
};

class QueuedTempEffect
{
public:
    bool sub_140146F20();

    std::uint64_t     unk00;   // 00
    std::uint32_t     unk08;   // 08
    std::uint32_t     state;   // 0C
    std::uint64_t     unk10;   // 10
    TempEffectTarget* target;  // 18
};
static_assert(sizeof(QueuedTempEffect) == 0x20, "QueuedTempEffect size");
