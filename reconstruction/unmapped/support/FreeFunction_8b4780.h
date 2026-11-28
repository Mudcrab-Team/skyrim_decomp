// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// TlsInner8b4780, TlsOuter8b4780, Target8b4780, FlagHolder8b4780, Context8b4780, NotifyFirst8b4780, Function8b4780, g_tlsContext_tls_0x6a0, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Slot9, Slot10, Slot11, ApplyContext, unk00, payload, inner, flags, first, unk08, second, third, arg, ctx: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct TlsInner8b4780
{
    std::uint64_t unk00[4];  // 0x00
    void* payload;           // 0x20
};
static_assert(offsetof(TlsInner8b4780, payload) == 0x20, "TlsInner8b4780 payload offset");

struct TlsOuter8b4780
{
    std::uint8_t unk00[0x158];  // 0x000
    TlsInner8b4780* inner;      // 0x158
};
static_assert(offsetof(TlsOuter8b4780, inner) == 0x158, "TlsOuter8b4780 inner offset");

struct Target8b4780
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void ApplyContext(void* payload);
};

struct FlagHolder8b4780
{
    std::uint8_t unk00[0x3C];  // 0x00
    std::uint32_t flags;       // 0x3C
};
static_assert(offsetof(FlagHolder8b4780, flags) == 0x3C, "FlagHolder8b4780 flags offset");

struct Context8b4780
{
    void* first;              // 0x00
    std::uint64_t unk08;      // 0x08
    Target8b4780* second;     // 0x10
    FlagHolder8b4780* third;  // 0x18
};
static_assert(sizeof(Context8b4780) == 0x20, "Context8b4780 size");

extern __declspec(thread) TlsOuter8b4780* g_tlsContext_tls_0x6a0;

void NotifyFirst8b4780(void* first, std::uint32_t arg);
void Function8b4780(Context8b4780* ctx);
