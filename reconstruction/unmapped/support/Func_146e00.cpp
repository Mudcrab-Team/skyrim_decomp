// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x146e00 Func_146e00::~Func_146e00
// Adapted bodies: none
#include "Func_146e00.h"

// Releases derived state before delegating to the base destructor.
// guess: the CrashLogger PDB names the called address TESPackage::Copy; its role here is not known.
Func_146e00::~Func_146e00()
{
    Cleanup();
}
