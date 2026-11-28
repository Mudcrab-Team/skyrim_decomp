// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; explicit instantiation of a standard library template over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// 0x13bd20 std::allocator<Pair13bd20>::destroy
// CI hash: 0x13bd20 ??$destroy@UPair13bd20@@@?$allocator@UPair13bd20@@@std@@QEAAXPEAUPair13bd20@@@Z
// Adapted bodies: none
#include "Pair13bd20.h"

// PDB: the CrashLogger PDB name is destroy<>; the stand-in name here is kept.
template void std::allocator<Pair13bd20>::destroy<Pair13bd20>(Pair13bd20*);
