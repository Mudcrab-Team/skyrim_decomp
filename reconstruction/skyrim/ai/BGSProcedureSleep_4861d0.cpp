// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x4861d0 BGSProcedureSleep::HasStateName
#include "BGSProcedureSleep_4861d0.h"

extern const ProcedureStateName gSitSleepStateName;

bool BGSProcedureSleep::HasStateName(const ProcedureExecutionState& state) const
{
    return state.GetStateName().text == gSitSleepStateName.text;
}
