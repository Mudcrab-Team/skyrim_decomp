// CI hash: 0x1e6bb0 ?Function1e6bb0@Unk1e6bb0@@QEAA_NI@Z
// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk1e6bb0: GUESS(low)
// Unk1e6bb0::Function1e6bb0: GUESS(low)
// Unk1e6bb0::unk14, Unk1e6bb0::kTestMask: GUESS(low)
// 0x1e6bb0 Unk1e6bb0::Function1e6bb0
#include "Unk1e6bb0_1e6bb0.h"

// Return the stored condition.
bool Unk1e6bb0::Function1e6bb0(std::uint32_t value)
{
    return (((unk14 ^ value) & kTestMask) == 0);
}
