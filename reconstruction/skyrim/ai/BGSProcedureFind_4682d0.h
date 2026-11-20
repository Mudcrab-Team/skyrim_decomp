// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureFind: EXE_RTTI
// FindStateData, FindStateRequest, PrepareProcedureState, PrepareState, input, state, stateData, unknown00: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

struct FindStateData
{
    void* unknown00;
    void* stateData;
};

struct FindStateRequest
{
    const void* input;
    FindStateData* state;
};

class BGSProcedureFind : public BGSProcedureBase
{
public:
    void PrepareState(const FindStateRequest& request);
};
