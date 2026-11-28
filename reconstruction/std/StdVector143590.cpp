// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer element type
// SPDX-License-Identifier: CC0-1.0
// 0x143590 std::vector<StdVector143590*>::~vector
// CI hash: 0x143590 ??1?$vector@PEAUStdVector143590@@V?$allocator@PEAUStdVector143590@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "StdVector143590.h"

// PDB: the CrashLogger PDB marks this address as a FID_conflict vector destructor over another pointer type; the element type here is a stand-in.
template class std::vector<StdVector143590*>;
