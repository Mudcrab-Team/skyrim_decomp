// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Func_13f9f0: GUESS(low)
#pragma once

#include <cstdint>

struct Func_13f9f0
{
    using Callback = void (*)(void*, std::uint32_t, void*, std::uint32_t);

    void Invoke(void*&& arg0, std::uint32_t&& arg1, void* arg2, std::uint32_t&& arg3);

    Callback fn;
};
