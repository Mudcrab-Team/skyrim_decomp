// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureSit: EXE_RTTI
// HasStateName, gSitSleepStateName: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

class BGSProcedureSit : public BGSProcedureBase
{
public:
    bool HasStateName(const ProcedureExecutionState& state) const;
};
