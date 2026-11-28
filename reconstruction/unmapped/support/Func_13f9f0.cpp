// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13f9f0 Func_13f9f0::Invoke
// Adapted bodies: none
#include "Func_13f9f0.h"

// Forwards unpacked arguments to the stored callback pointer.
void Func_13f9f0::Invoke(void*&& arg0, std::uint32_t&& arg1, void* arg2, std::uint32_t&& arg3)
{
    fn(arg0, arg1, arg2, arg3);
}
