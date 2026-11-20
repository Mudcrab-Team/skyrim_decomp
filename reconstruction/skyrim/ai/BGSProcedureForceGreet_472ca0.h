// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureForceGreet: EXE_RTTI
// HasStateName, gForceGreetStateName: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

class BGSProcedureForceGreet : public BGSProcedureBase
{
public:
    bool HasStateName(const ProcedureExecutionState& state) const;
};
