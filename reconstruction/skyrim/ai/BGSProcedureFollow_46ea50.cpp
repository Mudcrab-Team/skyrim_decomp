// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x46ea50 BGSProcedureFollow::HasStateName
// 0x46f030 BGSProcedureFollow::GetStateStatus
#include "BGSProcedureFollow_46ea50.h"

extern const ProcedureStateName gFollowStateName;

bool BGSProcedureFollow::HasStateName(const ProcedureExecutionState& state) const
{
    return state.GetStateName().text == gFollowStateName.text;
}

std::uint8_t BGSProcedureFollow::GetStateStatus(const FollowStateRequest& request) const
{
    return request.state->status;
}
