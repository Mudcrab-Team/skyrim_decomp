// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x258690 TESRegionObject258690::~TESRegionObject258690
// Adapted bodies: none
#include "TESRegionObject258690.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESRegionObject258690::TESRegionObject258690()
{
}

// Delete the child region object list before base teardown.
TESRegionObject258690::~TESRegionObject258690()
{
    delete childrenList;
}
