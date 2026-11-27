// Source exposure: mixed (pinned-image observations and labelled naming/declaration sources).
// Code origin: original handwritten implementation from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x121ae30 MovementMessageFreezeDirection::Function121ae30
// Adapted bodies: none
#include "MovementMessageFreezeDirection_121ae30.h"

void MovementMessageFreezeDirection::Function121ae30(BSPathingStreamRead* stream)
{
    std::uint32_t value = 0;
    stream->ReadValue(&value);
    eFreeze = value;
}
