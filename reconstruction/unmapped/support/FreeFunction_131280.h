// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Callback131280, Function131280: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

using Callback131280 = void (*)(std::uint64_t, std::uint32_t, const void*, std::uint32_t);

void Function131280(Callback131280 a_fn, const std::uint64_t& a_arg1, const std::uint32_t& a_arg2, const void* a_arg3, const std::uint32_t& a_arg4);  // compared: 0x131280
