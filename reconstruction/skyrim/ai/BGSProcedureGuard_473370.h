// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureGuard: EXE_RTTI
// GuardStateData, GuardStateRequest, PrepareProcedureState, PrepareState, input, state, stateData, unknown00: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

struct GuardStateData
{
    void* unknown00;
    void* stateData;
};

struct GuardStateRequest
{
    const void* input;
    GuardStateData* state;
};

class BGSProcedureGuard : public BGSProcedureBase
{
public:
    void PrepareState(const GuardStateRequest& request);
};
