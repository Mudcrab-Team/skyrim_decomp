// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6d4c80 Actor::sub_1406302B0
// Adapted bodies: none
#include "Actor_6d4c80.h"

// Delete and clear each allocated magic caster under the thread-local cleanup state.
void Actor::sub_1406302B0()
{
    ThreadStateScope6d4c80 scope(0x5f);
    for (std::uint32_t i = 0; i < 4; ++i) {
        if (magicCasters[i]) {
            delete magicCasters[i];
            magicCasters[i] = nullptr;
        }
    }
}
