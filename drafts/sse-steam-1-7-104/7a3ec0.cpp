// Near miss: 11.5 alignment distance | control-flow
// Exposure detail: (local pinned-image observations; permitted sibling game-code study).
// Source exposure: mixed
// Code origin: original reconstruction; no external bodies used.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x7a3ec0 MovementHandlerAgentPlayerControls::Func7_1406FB980

#include "include/7a3ec0/MovementHandlerAgentPlayerControls_7a3ec0.h"

void MovementHandlerAgentPlayerControls::Func7_1406FB980(PlayerInputStream* stream)
{
    inputSink.SetInput(stream->ReadInput().value);
}
