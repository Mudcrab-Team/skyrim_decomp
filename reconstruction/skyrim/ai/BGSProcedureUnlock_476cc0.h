// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureUnlock: EXE_RTTI
// PrepareProcedureState, PrepareState, UnlockStateData, UnlockStateRequest, completed, entered, input, state, stateData, unknown00, unknown11: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

struct UnlockStateData
{
    void* unknown00;
    void* stateData;
    bool entered;
    bool unknown11;
    bool completed;
};

struct UnlockStateRequest
{
    const void* input;
    UnlockStateData* state;
};

class BGSProcedureUnlock : public BGSProcedureBase
{
public:
    void PrepareState(const UnlockStateRequest& request);
};
