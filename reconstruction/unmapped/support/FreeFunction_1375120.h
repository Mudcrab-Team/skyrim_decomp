// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Connection_1375120, CloseHandle, GetLastError, Function1375120, unk00, handle, unk220, lastError, unk228, closing, active, conn: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

extern "C" {
__declspec(dllimport) int __stdcall CloseHandle(void* handle);
__declspec(dllimport) unsigned long __stdcall GetLastError();
}

struct Connection_1375120
{
    std::uint8_t unk00[0x218];    // 0x0000
    void* handle;                 // 0x0218
    std::uint32_t unk220;         // 0x0220
    std::uint32_t lastError;      // 0x0224
    std::uint8_t unk228[0x0FC0];  // 0x0228
    char closing;                 // 0x11E8
    char active;                  // 0x11E9
};
static_assert(offsetof(Connection_1375120, handle) == 0x218, "handle offset");
static_assert(offsetof(Connection_1375120, lastError) == 0x224, "lastError offset");
static_assert(offsetof(Connection_1375120, closing) == 0x11E8, "closing offset");
static_assert(offsetof(Connection_1375120, active) == 0x11E9, "active offset");

void Function1375120(Connection_1375120* conn);
