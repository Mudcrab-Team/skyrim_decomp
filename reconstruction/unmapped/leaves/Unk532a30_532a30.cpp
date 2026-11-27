// CI hash: 0x532a30 ?Function532a30@Unk532a30@@QEAAII@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk532a30: STANDIN GUESS(low)
// Unk532a30::Function532a30: GUESS(low)
// Unk532a30::unknown0, Unk532a30::entries, ValueEntry532a30: GUESS(low)
// 0x532a30 Unk532a30::Function532a30
#include "Unk532a30_532a30.h"

// Read the indexed value from the trailing entry array.
std::uint32_t Unk532a30::Function532a30(std::uint32_t index)
{
    return entries[index].value;
}
