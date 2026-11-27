// CI hash: 0x5329f0 ?Function5329f0@Unk5329f0@@QEAAPEAIPEAII@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk5329f0: STANDIN GUESS(low)
// Unk5329f0::Function5329f0: GUESS(low)
// Unk5329f0::unknown0, Unk5329f0::entries, ValueEntry5329f0: GUESS(low)
// 0x5329f0 Unk5329f0::Function5329f0
#include "Unk5329f0_5329f0.h"

// Read or update the stored values.
std::uint32_t* Unk5329f0::Function5329f0(std::uint32_t* output, std::uint32_t index)
{
    *output = entries[index].value;
    return output;
}
