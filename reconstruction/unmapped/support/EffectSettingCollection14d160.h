// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// BaseForm14d160: GUESS(low)
// NameComponent14d160: GUESS(low)
// NamedItem14d160: GUESS(low)
// EffectSettingCollection14d160: GUESS(low)
// SortByName: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

struct BaseForm14d160
{
    virtual ~BaseForm14d160();
    std::uint64_t unk08[3];
};

static_assert(sizeof(BaseForm14d160) == 0x20, "BaseForm14d160 size");

struct NameComponent14d160
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual const char* GetName() const;
};

struct NamedItem14d160 : BaseForm14d160, NameComponent14d160
{
};

struct EffectSettingCollection14d160
{
    static int SortByName(const NamedItem14d160* lhs, const NamedItem14d160* rhs);
};
