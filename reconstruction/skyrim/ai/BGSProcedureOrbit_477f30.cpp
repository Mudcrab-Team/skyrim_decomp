// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x477f30 BGSProcedureOrbit::Run
// Adapted bodies: none
#include "BGSProcedureOrbit_477f30.h"

void BGSProcedureOrbit::Run(GrabArgs* args)
{
    Character** slot = args->actor;
    Character* actor = *slot;
    if (actor->Function673b40())
    {
        args->state->done = true;
    }
}
