// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x257bf0 RegionObj257bf0::~RegionObj257bf0
// Adapted bodies: none
#include "RegionObj257bf0.h"

// PDB: the CrashLogger PDB name is TESRegionObjectBase::ctor, although the compared body is a destructor; the stand-in name here is kept.
// Delete the child region object list before base teardown.
RegionObj257bf0::~RegionObj257bf0()
{
    delete childrenList;
}
