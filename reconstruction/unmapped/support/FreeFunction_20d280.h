// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// FixedString20d280, GetStringLength20d280, g_prefix20d280, Function20d280, data, str, _strnicmp: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct FixedString20d280
{
    const char* data;  // 0x00
};
static_assert(sizeof(FixedString20d280) == 0x8, "FixedString20d280 size");

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* lhs, const char* rhs, std::size_t count);

extern const char g_prefix20d280[5];

std::uint32_t GetStringLength20d280(const FixedString20d280* str);
std::uint32_t Function20d280(const FixedString20d280* str);
