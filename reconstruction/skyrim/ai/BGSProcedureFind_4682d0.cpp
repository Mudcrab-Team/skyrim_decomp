// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x4682d0 BGSProcedureFind::PrepareState
#include "BGSProcedureFind_4682d0.h"

void PrepareProcedureState(BGSProcedureFind& procedure, const FindStateRequest& request, bool option, void** state);

void BGSProcedureFind::PrepareState(const FindStateRequest& request)
{
    return PrepareProcedureState(*this, request, false, &request.state->stateData);
}
