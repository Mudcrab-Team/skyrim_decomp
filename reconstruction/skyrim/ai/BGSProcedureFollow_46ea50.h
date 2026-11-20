// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureFollow: EXE_RTTI
// FollowStateData, FollowStateRequest, GetStateStatus, HasStateName, gFollowStateName, input, state, status, unknown00: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

struct FollowStateData
{
    std::uint8_t unknown00[0x3f];
    std::uint8_t status;
};

struct FollowStateRequest
{
    const void* input;
    FollowStateData* state;
};

class BGSProcedureFollow : public BGSProcedureBase
{
public:
    bool HasStateName(const ProcedureExecutionState& state) const;
    std::uint8_t GetStateStatus(const FollowStateRequest& request) const;
};
