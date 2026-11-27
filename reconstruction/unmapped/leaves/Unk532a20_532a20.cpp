// CI hash: 0x532a20 ?Function532a20@Unk532a20@@QEAA_KI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk532a20: STANDIN GUESS(low)
// Unk532a20::Function532a20: GUESS(low)
// Unk532a20::unknown0, Unk532a20::entries, ValueEntry532a20: GUESS(low)
// 0x532a20 Unk532a20::Function532a20
#include "Unk532a20_532a20.h"

// Read the indexed value from the trailing entry array.
std::uint64_t Unk532a20::Function532a20(std::uint32_t index)
{
    return entries[index].value;
}
