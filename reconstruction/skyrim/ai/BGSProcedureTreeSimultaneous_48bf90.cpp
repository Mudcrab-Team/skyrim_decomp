// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x48bf90 BGSProcedureTreeSimultaneous::RunChildren
// Adapted bodies: none
#include "BGSProcedureTreeSimultaneous_48bf90.h"

void BGSProcedureTreeSimultaneous::RunChildren()
{
    bool done = false;
    const std::uint32_t count = childCount;
    for (std::uint32_t i = 0; i < count && !done; ++i)
    {
        done = children[i]->Vfunc11();
    }
}
