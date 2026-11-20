// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x4742d0 BGSProcedureHoldPositionExecState::ApplyPosition
#include "BGSProcedureHoldPositionExecState_4742d0.h"

void ApplyActorPosition(PositionController& controller, const void* position);

void BGSProcedureHoldPositionExecState::ApplyPosition(const HoldPositionRequest& request)
{
    if (auto* controller = request.settings->controller) {
        return ApplyActorPosition(*controller, request.state->position);
    }
}
