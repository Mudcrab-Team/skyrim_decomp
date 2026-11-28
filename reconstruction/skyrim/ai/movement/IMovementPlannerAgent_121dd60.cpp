// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x121dd60 IMovementPlannerAgent::Func1_141109760
#include "IMovementPlannerAgent_121dd60.h"

// Forwards a payload value to the sub-agent when the controller state check succeeds.
void MovementPlannerAgentImpl::Func1_141109760(void* context, const PlannerPayload* payload)
{
    if (controller->CheckState(context))
    {
        subAgent.ApplyValue(payload->unk38);
    }
}
