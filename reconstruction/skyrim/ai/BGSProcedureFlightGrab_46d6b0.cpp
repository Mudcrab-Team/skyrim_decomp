// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x46d6b0 BGSProcedureFlightGrab::Run
// Adapted bodies: none
#include "BGSProcedureFlightGrab_46d6b0.h"

void BGSProcedureFlightGrab::Run(GrabArgs* args)
{
    Character** slot = args->actor;
    Character* actor = *slot;
    if (actor->Function673b40())
    {
        args->state->done = true;
    }
}
