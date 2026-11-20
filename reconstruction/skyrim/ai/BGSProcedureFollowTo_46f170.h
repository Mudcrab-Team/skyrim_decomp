// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureFollowTo: EXE_RTTI
// HasStateName, gFollowStateName: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

class BGSProcedureFollowTo : public BGSProcedureBase
{
public:
    bool HasStateName(const ProcedureExecutionState& state) const;
};
