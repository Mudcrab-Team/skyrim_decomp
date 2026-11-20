// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x465720 BGSProcedureEscort::GetStateData
#include "BGSProcedureEscort_465720.h"

std::uint8_t* BGSProcedureEscort::GetStateData(const EscortStateRequest& request) const
{
    return &request.state->payload;
}
