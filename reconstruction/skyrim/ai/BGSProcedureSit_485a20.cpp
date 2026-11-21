// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x485a20 BGSProcedureSit::HasStateName
#include "BGSProcedureSit_485a20.h"

extern const ProcedureStateName gSitSleepStateName;

bool BGSProcedureSit::HasStateName(const ProcedureExecutionState& state) const
{
    return state.GetStateName().text == gSitSleepStateName.text;
}
