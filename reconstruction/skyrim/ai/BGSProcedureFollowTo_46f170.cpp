// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x46f170 BGSProcedureFollowTo::HasStateName
#include "BGSProcedureFollowTo_46f170.h"

extern const ProcedureStateName gFollowStateName;

bool BGSProcedureFollowTo::HasStateName(const ProcedureExecutionState& state) const
{
    return state.GetStateName().text == gFollowStateName.text;
}
