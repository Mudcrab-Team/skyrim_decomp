// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureEscort: EXE_RTTI
// EscortStateData, EscortStateRequest, GetStateData, input, payload, state, unknown00: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

struct EscortStateData
{
    std::uint8_t unknown00[0x10];
    std::uint8_t payload;
};

struct EscortStateRequest
{
    const void* input;
    EscortStateData* state;
};

class BGSProcedureEscort : public BGSProcedureBase
{
public:
    std::uint8_t* GetStateData(const EscortStateRequest& request) const;
};
