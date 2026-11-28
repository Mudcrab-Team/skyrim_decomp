// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ThreadHolder1385cf0, Function1385cf0: GUESS(low) STANDIN
#pragma once

#include <cstdint>

extern "C" {
__declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* a_handle, unsigned long a_milliseconds);
__declspec(dllimport) int __stdcall CloseHandle(void* a_handle);
}

struct ThreadHolder1385cf0
{
    std::uint64_t unk00;  // 0x00
    void* handle;         // 0x08
};

void Function1385cf0(ThreadHolder1385cf0* a_holder);  // compared: 0x1385cf0
