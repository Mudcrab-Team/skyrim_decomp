// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2d63b0::SetFlagBit, treated as adapted: shaped like a thread local flag setter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00540000_o2.cpp:29502
// SPDX-License-Identifier: CC0-1.0
// gFlags_tls_0x670, Obj2d63b0, Obj2d63b0::SetFlagBit: GUESS(low)
#pragma once

#include <cstdint>

extern __declspec(thread) std::uint32_t gFlags_tls_0x670;

class Obj2d63b0
{
public:
    bool SetFlagBit(bool a_clear);
};
