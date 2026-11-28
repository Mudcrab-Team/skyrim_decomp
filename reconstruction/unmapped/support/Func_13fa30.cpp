// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13fa30 Func_13fa30::Invoke
// Adapted bodies: none
#include "Func_13fa30.h"

// Forwards unpacked arguments to the callback pointer passed in fn.
void Func_13fa30::Invoke(Callback fn, void*&& arg0, std::uint32_t&& arg1, void* arg2, std::uint32_t&& arg3)
{
    fn(arg0, arg1, arg2, arg3);
}
