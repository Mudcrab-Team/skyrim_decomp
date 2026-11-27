// CI hash: 0x24a230 ?Function24a230@Unk24a230@@SAHPEAPEBXH@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk24a230: STANDIN GUESS(low)
// Unk24a230::Function24a230: GUESS(low)
// TrackEntry24a230, gTrackingEnabled, gTrackingEntries, gTrackingCount: GUESS(low)
// 0x24a230 Unk24a230::Function24a230
#include "Unk24a230_24a230.h"

// Adjust a tracked entry with matching pointer identity.
std::int32_t Unk24a230::Function24a230(const void** key, std::int32_t delta)
{
    std::int32_t result = -1;
    if (gTrackingEnabled) {
        for (std::uint32_t index = 0; index < gTrackingCount; ++index) {
            if (gTrackingEntries[index].key == *key) {
                gTrackingEntries[index].value += delta;
                result = gTrackingEntries[index].value;
                index = gTrackingCount;
            }
        }
    }
    return result;
}
