// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// TestBit2e4990, Target2e4990, Obj2e4990, Obj2e4990::HasFlag15: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

// TestBit2e4990: GUESS(low); a flag-word bit test by bit index, taking the word by value (cookbook rule 16).
inline bool TestBit2e4990(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

struct Target2e4990
{
    std::uint64_t unk00[2];  // 0x00
    std::uint32_t m_flags;   // 0x10
};
static_assert(offsetof(Target2e4990, m_flags) == 0x10, "m_flags offset");

class Obj2e4990
{
public:
    bool HasFlag15() const;

    std::uint64_t unk00[8];  // 0x00
    Target2e4990* m_target;  // 0x40
};
static_assert(offsetof(Obj2e4990, m_target) == 0x40, "m_target offset");
