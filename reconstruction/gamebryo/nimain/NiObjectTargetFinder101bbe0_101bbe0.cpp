// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// Adapted bodies: none
// 0x101bbe0 NiObjectTargetFinder101bbe0::FindControllerManagerTarget
#include "NiObjectTargetFinder101bbe0_101bbe0.h"

// Locates the matching controller manager on this object and returns its target pointer.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
StandinTarget101bbe0* NiObjectTargetFinder101bbe0::FindControllerManagerTarget()
{
    StandinController101bbe0* found = nullptr;
    if (AsNode())
    {
        StandinController101bbe0* ctrl = controllers;
        if (!ctrl || !ctrl->IsKindOf(&StandinControllerManager101bbe0::ms_RTTI))
        {
            return nullptr;
        }
        found = ctrl;
    }
    else
    {
        for (StandinController101bbe0* ctrl = controllers; ctrl; ctrl = ctrl->next)
        {
            if (ctrl->IsKindOf(&StandinControllerManager101bbe0::ms_RTTI))
            {
                found = ctrl;
                break;
            }
        }
        if (!found)
        {
            return nullptr;
        }
    }
    return found->target;
}
