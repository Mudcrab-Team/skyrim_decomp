// Source exposure: mixed (local target observations; permitted sibling game-code study).
// Code origin: original reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none.
// 0x7a4950 MovementHandlerAgentPlayerControls::Func12_1406FC1F0
#include "MovementHandlerAgentPlayerControls_7a4950.h"

void MovementHandlerAgentPlayerControls::Func12_1406FC1F0(PlayerInputStream* stream)
{
    {
        std::uint32_t value;
        stream->ReadValue4(&value);
        unknown38 = value;
    }
    stream->ReadValue1(&unknown48);
    return stream->ReadValue10(&unknown4c);
}
