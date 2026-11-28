// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit20f530, Slot01, ReleaseStream, unk08, flags, Close20f530: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Unit20f530
{
    virtual ~Unit20f530();
    virtual void Slot01();
    virtual void ReleaseStream();

    std::uint64_t unk08;  // 08
    long flags;           // 10

    void Close20f530();  // compared: 0x20f530
};
static_assert(offsetof(Unit20f530, flags) == 0x10, "Unit20f530::flags offset");
