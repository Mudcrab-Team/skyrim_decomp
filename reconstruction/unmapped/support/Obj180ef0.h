// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// LockData180ef0, Obj180ef0, IsNotEqual, g_lockThresh0_180ef0, g_lockThresh1_180ef0, g_lockThresh2_180ef0, g_lockThresh3_180ef0, g_lockThresh4_180ef0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern std::int32_t g_lockThresh0_180ef0;
extern std::int32_t g_lockThresh1_180ef0;
extern std::int32_t g_lockThresh2_180ef0;
extern std::int32_t g_lockThresh3_180ef0;
extern std::int32_t g_lockThresh4_180ef0;

struct LockData180ef0
{
    std::int32_t GetDifficultyRank() const
    {
        std::int32_t lvl = level00;
        if (lvl <= g_lockThresh0_180ef0) {
            return 0;
        }
        if (lvl <= g_lockThresh1_180ef0) {
            return 1;
        }
        if (lvl <= g_lockThresh2_180ef0) {
            return 2;
        }
        if (lvl <= g_lockThresh3_180ef0) {
            return 3;
        }
        return (lvl <= g_lockThresh4_180ef0) ? 4 : 5;
    }

    std::uint8_t level00;     // 00
    void* key08;              // 08
    std::uint8_t flags10;     // 10
    std::uint32_t unk14;      // 14
    std::uint32_t unk18;      // 18
};

struct Obj180ef0
{
    bool IsNotEqual(const Obj180ef0* a_rhs) const;  // compared: 0x180ef0

    std::uint8_t unk00[0x10];  // 00
    LockData180ef0* lock10;    // 10
};
