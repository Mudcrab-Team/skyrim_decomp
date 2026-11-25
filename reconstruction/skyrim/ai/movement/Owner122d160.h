// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7a5c80 (skyrim/ai/movement/MovementHandlerAgentSprintActionTrigger_7a5c80): source copied, names replaced by placeholders.
// BSPathingStreamRead: SYMBOLS(fo4-pdb) GUESS(low); the method name and slot are placeholders
// Owner122d160: GUESS(low) STANDIN
#pragma once
#include "MovementHandlerAgentSprintActionTrigger_7a5c80.h"

class Owner122d160
{
public:
    virtual void Init(BSPathingStreamRead* stream);

    unsigned char pad08[0x20];
    std::uint32_t eState;
};

