// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x142b80 Func_142b80::Invoke
// Adapted bodies: none
#include "Func_142b80.h"

// Forwards unpacked arguments to the stored callback pointer.
void Func_142b80::Invoke(void*&& arg0, std::uint32_t&& arg1, void* arg2, std::uint32_t&& arg3)
{
    fn(arg0, arg1, arg2, arg3);
}
