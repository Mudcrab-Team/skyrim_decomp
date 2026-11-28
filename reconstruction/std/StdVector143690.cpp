// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer element type
// SPDX-License-Identifier: CC0-1.0
// 0x143690 std::vector<StdVector143690*>::~vector
// CI hash: 0x143690 ??1?$vector@PEAUStdVector143690@@V?$allocator@PEAUStdVector143690@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "StdVector143690.h"

// PDB: the CrashLogger PDB marks this address as a FID_conflict vector destructor over another pointer type; the element type here is a stand-in.
template class std::vector<StdVector143690*>;
