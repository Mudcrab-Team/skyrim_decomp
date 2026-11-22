// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// Code origin: original reconstruction from the pinned image listing; names as labelled below.
// SPDX-License-Identifier: CC0-1.0
// 0x5d2e40 MagicTarget::GetMagicTargetFormID
#include "MagicTarget_5d2e40.h"

std::uint32_t MagicTarget::GetMagicTargetFormID()
{
    if (MagicTargetIsActor()) {
        // an actor embeds its MagicTarget base; its form ID sits 0x8C bytes before this base
        return *reinterpret_cast<const std::uint32_t*>(reinterpret_cast<const std::uint8_t*>(this) - 0x8C);
    }
    return GetTargetStatsObject()->formID;
}
