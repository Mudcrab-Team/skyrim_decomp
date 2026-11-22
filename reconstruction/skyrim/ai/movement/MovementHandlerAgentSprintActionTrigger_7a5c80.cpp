// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x7a5c80 MovementHandlerAgentSprintActionTrigger::Init
// Adapted bodies: none
#include "MovementHandlerAgentSprintActionTrigger_7a5c80.h"

void MovementHandlerAgentSprintActionTrigger::Init(BSPathingStreamRead* stream)
{
    std::uint32_t state;
    stream->ReadValue(&state);
    eState = state;
}
