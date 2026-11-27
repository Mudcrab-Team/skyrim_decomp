// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkbAnimationGraph: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BShkbAnimationGraph::Functionbd0660: GUESS(low)
// 0xbd0660 BShkbAnimationGraph::Functionbd0660
#include "BShkbAnimationGraph_bd0660.h"

// Return the hashed animation entry for a valid index, otherwise the default entry.
const HashedAnimEntry* BShkbAnimationGraph::Functionbd0660(std::int16_t a_index) const
{
    if (a_index >= 0) {
        const std::uint32_t index = static_cast<std::uint32_t>(a_index);
        if (index < data->count) {
            return &data->entries[index];
        }
    }
    return GetDefaultHashedAnim();
}
