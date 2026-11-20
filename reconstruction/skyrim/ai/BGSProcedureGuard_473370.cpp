// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x473370 BGSProcedureGuard::PrepareState
#include "BGSProcedureGuard_473370.h"

void PrepareProcedureState(BGSProcedureGuard& procedure, const GuardStateRequest& request, bool option, void** state);

void BGSProcedureGuard::PrepareState(const GuardStateRequest& request)
{
    return PrepareProcedureState(*this, request, false, &request.state->stateData);
}
