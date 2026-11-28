// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Obj3134c0, Obj3134c0::FindIndex: GUESS(low)
#pragma once

#include <cstdint>

class Obj3134c0
{
public:
    std::uint32_t FindIndex(void* const& a_item) const;

    void** m_data;         // 0x00
    std::uint64_t unk08;   // 0x08
    std::uint32_t m_size;  // 0x10
};
