// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x476cc0 BGSProcedureUnlock::PrepareState
#include "BGSProcedureUnlock_476cc0.h"

void PrepareProcedureState(BGSProcedureUnlock& procedure, const UnlockStateRequest& request, bool option, void** state);

void BGSProcedureUnlock::PrepareState(const UnlockStateRequest& request)
{
    auto* state = request.state;
    PrepareProcedureState(*this, request, false, &state->stateData);
    state->entered = false;
    state->completed = false;
}
