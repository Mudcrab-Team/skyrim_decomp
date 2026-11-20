// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x472ca0 BGSProcedureForceGreet::HasStateName
#include "BGSProcedureForceGreet_472ca0.h"

extern const ProcedureStateName gForceGreetStateName;

bool BGSProcedureForceGreet::HasStateName(const ProcedureExecutionState& state) const
{
    return state.GetStateName().text == gForceGreetStateName.text;
}
