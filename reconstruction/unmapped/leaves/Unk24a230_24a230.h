// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk24a230: STANDIN GUESS(low)
// Unk24a230::Function24a230: GUESS(low)
// TrackEntry24a230, gTrackingEnabled, gTrackingEntries, gTrackingCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct TrackEntry24a230 { const void* key; std::uint64_t unknown08; std::int32_t value; std::uint8_t unknown14[12]; };
extern bool gTrackingEnabled;
extern TrackEntry24a230* gTrackingEntries;
extern std::uint32_t gTrackingCount;
class Unk24a230
{
public:
    static std::int32_t Function24a230(const void** key, std::int32_t delta);
};
