// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x69f920 (skyrim_shared/actors/Actor_69f920): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x6a68f0 Owner6a68f0::Function6a68f0
#include "Owner6a68f0.h"

// guess: same compiled code as matched 0x69f920 apart from relocated fields; its role here is not established.
std::uint8_t Owner6a68f0::Function6a68f0(BGSPerk* a_perk)
{
    if (currentProcess) {
        return currentProcess->HasPerk(reinterpret_cast<Actor*>(this), a_perk);
    }
    return 0;
}
