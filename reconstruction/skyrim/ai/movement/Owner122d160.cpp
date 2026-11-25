// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header Stamped as a twin of matched 0x7a5c80 (skyrim/ai/movement/MovementHandlerAgentSprintActionTrigger_7a5c80): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// 0x122d160 Owner122d160::Init
#include "Owner122d160.h"

// guess: same compiled code as matched 0x7a5c80 apart from relocated fields; its role here is not established.
void Owner122d160::Init(BSPathingStreamRead* stream)
{
    std::uint32_t state;
    stream->ReadValue(&state);
    eState = state;
}
