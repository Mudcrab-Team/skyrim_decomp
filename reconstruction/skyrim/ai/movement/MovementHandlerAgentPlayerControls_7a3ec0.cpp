// Source exposure: mixed (local pinned-image observations; permitted sibling game-code study).
// Code origin: original reconstruction; no external bodies used.
// SPDX-License-Identifier: CC0-1.0
// 0x7a3ec0 MovementHandlerAgentPlayerControls::Func7_1406FB980
// Adapted bodies: none
#include "MovementHandlerAgentPlayerControls_7a3ec0.h"

void MovementHandlerAgentPlayerControls::Func7_1406FB980(PlayerInputStream* stream)
{
    std::uint32_t input;
    // The returned value object lives only in this scope, so the sink call is the last action and ends as a tail call.
    {
        PlayerInputValue read = stream->ReadInput();
        input = read.value;
    }
    inputSink.SetInput(input);
}
