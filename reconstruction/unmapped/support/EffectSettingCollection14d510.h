// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Item14d510: GUESS(low)
// ListNode14d510: GUESS(low)
// gEffectList14d510: GUESS(low)
// EffectSettingCollection14d510: GUESS(low)
// InitItems: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

struct Item14d510
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void InitItem();
};

struct ListNode14d510
{
    Item14d510* item;
    ListNode14d510* next;
};

extern ListNode14d510 gEffectList14d510;

struct EffectSettingCollection14d510
{
    static void InitItems();
};
