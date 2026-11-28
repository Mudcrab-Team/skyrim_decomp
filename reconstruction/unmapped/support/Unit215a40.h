// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Node215a40, Manager215a40, Unit215a40, unk00, kind, GetNext, overridePtr, GetFirstNode, ComputeValue215a40, g_manager215a40, g_baseValue215a40, g_altPenalty215a40, g_defaultPenalty215a40: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Node215a40
{
    std::uint8_t unk00[0x14];  // 00
    std::uint32_t kind;        // 14

    Node215a40* GetNext(std::uint32_t a_flag);
};
static_assert(offsetof(Node215a40, kind) == 0x14, "Node215a40::kind offset");

struct Manager215a40
{
    std::uint8_t unk00[0xC0];  // 00
    void* overridePtr;         // C0

    Node215a40* GetFirstNode();
};
static_assert(offsetof(Manager215a40, overridePtr) == 0xC0, "Manager215a40::overridePtr offset");

extern Manager215a40* g_manager215a40;
extern std::int32_t g_baseValue215a40;
extern std::int32_t g_altPenalty215a40;
extern std::int32_t g_defaultPenalty215a40;

struct Unit215a40
{
    static std::int32_t ComputeValue215a40();  // compared: 0x215a40
};
