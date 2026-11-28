// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// TESValueForm, TESValueForm::sub_1401A1590: CRASHLOGGER_PDB(59818@2026.10.24)
// TESForm1f3610, AddChange, value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm1f3610
{
public:
    virtual ~TESForm1f3610();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09();
    virtual void AddChange(std::uint32_t a_flags);  // 0x0A (0x50)
};

class TESValueForm
{
public:
    virtual ~TESValueForm();

    void sub_1401A1590(std::int32_t a_value);  // compared: 0x1f3610

    std::int32_t value;  // 08
};
static_assert(offsetof(TESValueForm, value) == 0x08, "value offset");
