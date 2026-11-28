// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// JournalTab, JournalTab::dtor: CRASHLOGGER_PDB(59818@2026.10.24)
// GMemoryHeap, GRefCountImplCore, FxDelegateHandler, JournalView, gGlobalHeap, Free, OnTabDestroyed, refCount, view: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class GMemoryHeap
{
public:
    virtual ~GMemoryHeap();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Free(void* a_ptr);  // 0C (0x60)
};

extern GMemoryHeap* gGlobalHeap;

class JournalView
{
public:
    virtual ~JournalView();  // 00
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot3A();
    virtual void Slot3B();
    virtual void Slot3C();
    virtual void Slot3D();
    virtual void Slot3E();
    virtual void Slot3F();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void OnTabDestroyed();  // 45 (0x228)
};

class GRefCountImplCore
{
public:
    virtual ~GRefCountImplCore();

    static void operator delete(void* a_ptr)
    {
        gGlobalHeap->Free(a_ptr);
    }

    std::int32_t refCount;  // 08
};
static_assert(sizeof(GRefCountImplCore) == 0x10, "GRefCountImplCore size");

class FxDelegateHandler : public GRefCountImplCore
{
public:
    ~FxDelegateHandler() override {}
};
static_assert(sizeof(FxDelegateHandler) == 0x10, "FxDelegateHandler size");

class JournalTab : public FxDelegateHandler
{
public:
    JournalTab();
    ~JournalTab() override;  // compared: 0x9a3180

    JournalView* view;  // 10
};
static_assert(sizeof(JournalTab) == 0x18, "JournalTab size");
