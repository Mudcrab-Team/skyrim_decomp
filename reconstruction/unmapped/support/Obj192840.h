// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Obj192840, FormatBuffer192840, gFormat192840, FormatDescription: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern const char gFormat192840[];
std::int32_t FormatBuffer192840(char* a_buf, std::size_t a_size, const char* a_fmt, ...);

struct Obj192840
{
    bool FormatDescription(char* a_buf, std::uint32_t a_size) const;  // compared: 0x192840

    std::uint8_t unk00[0x308];  // 000
    const char* unk308;         // 308
};
