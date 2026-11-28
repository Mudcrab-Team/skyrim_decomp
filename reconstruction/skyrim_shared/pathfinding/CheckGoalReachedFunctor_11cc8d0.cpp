// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x11cc8d0 CheckGoalReachedFunctor::Func1_1410BA7F0
#include "CheckGoalReachedFunctor_11cc8d0.h"

// Checks whether the goal threshold and path completion criteria are met.
bool CheckGoalReachedFunctor::Func1_1410BA7F0(GoalContext11cc8d0* context)
{
    if (context->unk40 >= unk08)
    {
        if ((context->unk18->unk83 & 3) != 1)
        {
            return true;
        }
        if (context->unk40 >= static_cast<float>(context->unk20->unkA0 - 1))
        {
            return true;
        }
        if (context->unk28->GetMetric() >= kThreshold11cc8d0)
        {
            return false;
        }
        return true;
    }

    return false;
}
