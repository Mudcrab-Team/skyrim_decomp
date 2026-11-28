// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// GASFnCall, GASFnCall::Arg: CRASHLOGGER_PDB(59818@2026.10.24)
// GASValue, GASEnvironment, env, firstArgBottomIndex, current, pageStart, pages, numPages: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct GASValue
{
    std::uint64_t unk00[4];  // 00
};
static_assert(sizeof(GASValue) == 0x20, "GASValue size");

struct GASEnvironment
{
    std::uint64_t unk00[2];  // 00
    GASValue* current;  // 10
    GASValue* pageStart;  // 18
    std::uint64_t unk20[2];  // 20
    GASValue** pages;  // 30
    std::uint32_t numPages;  // 38
    std::uint32_t unk3C;  // 3C
};
static_assert(offsetof(GASEnvironment, current) == 0x10, "current offset");
static_assert(offsetof(GASEnvironment, pageStart) == 0x18, "pageStart offset");
static_assert(offsetof(GASEnvironment, pages) == 0x30, "pages offset");
static_assert(offsetof(GASEnvironment, numPages) == 0x38, "numPages offset");

class GASFnCall
{
public:
    GASValue* Arg(std::uint32_t a_index);  // compared: 0xd0c7f0

    std::uint64_t unk00[6];  // 00
    GASEnvironment* env;  // 30
    std::uint32_t unk38;  // 38
    std::uint32_t firstArgBottomIndex;  // 3C
};
static_assert(offsetof(GASFnCall, env) == 0x30, "env offset");
static_assert(offsetof(GASFnCall, firstArgBottomIndex) == 0x3C, "firstArgBottomIndex offset");
