// CI hash: 0x532a10 ?Function532a10@Unk532a10@@QEAA_KI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk532a10: STANDIN GUESS(low)
// Unk532a10::Function532a10: GUESS(low)
// Unk532a10::unknown0, Unk532a10::entries, ValueEntry532a10: GUESS(low)
// 0x532a10 Unk532a10::Function532a10
#include "Unk532a10_532a10.h"

// Read the indexed value from the trailing entry array.
std::uint64_t Unk532a10::Function532a10(std::uint32_t index)
{
    return entries[index].value;
}
