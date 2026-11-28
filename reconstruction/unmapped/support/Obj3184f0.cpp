// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// 0x3184f0 Obj3184f0::~Obj3184f0
// Adapted bodies: none
#include "Obj3184f0.h"

// PDB: the CrashLogger PDB name is a deleting destructor of Concurrency::details::_Concurrent_queue_base_v4 (a shared body is possible); the stand-in name here is kept.
// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Obj3184f0::Obj3184f0()
{
}
