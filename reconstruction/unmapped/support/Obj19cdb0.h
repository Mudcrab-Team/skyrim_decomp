// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// TlsEntry19cdb0, TlsTable19cdb0, Obj19cdb0, GetOrCreateThreadValue: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" {
    __declspec(dllimport) void* __stdcall TlsGetValue(std::uint32_t a_index);
    __declspec(dllimport) std::int32_t __stdcall TlsSetValue(std::uint32_t a_index, void* a_value);
    __declspec(dllimport) std::uint32_t __stdcall GetCurrentThreadId();
}

struct TlsEntry19cdb0
{
    std::uint32_t threadId;  // 00
    std::uint32_t unk04;     // 04
    void* value;             // 08
};

struct TlsTable19cdb0
{
    std::uint32_t maxSlots;  // 00
    std::uint32_t tlsIndex;  // 04
    TlsEntry19cdb0* entries; // 08
    long nextSlot;           // 10
};

struct Obj19cdb0
{
    virtual ~Obj19cdb0();
    virtual void* CreateSlot(std::uint32_t a_slot);

    void* GetOrCreateThreadValue();  // compared: 0x19cdb0

    std::uint8_t unk08[0x20];  // 08
    TlsTable19cdb0* table;     // 28
};
