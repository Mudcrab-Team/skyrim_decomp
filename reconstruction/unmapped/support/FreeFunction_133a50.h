// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Callback133a50, Function133a50: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

using Callback133a50 = void (*)(std::uint64_t, std::uint32_t, const void*, std::uint32_t);

void Function133a50(Callback133a50* a_fn, const std::uint64_t& a_arg1, const std::uint32_t& a_arg2, const void* a_arg3, const std::uint32_t& a_arg4);  // compared: 0x133a50
