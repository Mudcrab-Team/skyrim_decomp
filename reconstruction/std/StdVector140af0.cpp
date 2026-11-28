// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer element type
// SPDX-License-Identifier: CC0-1.0
// 0x140af0 std::vector<StdVector140af0*>::~vector
// CI hash: 0x140af0 ??1?$vector@PEAUStdVector140af0@@V?$allocator@PEAUStdVector140af0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "StdVector140af0.h"

// PDB: the CrashLogger PDB marks this address as a FID_conflict vector destructor over another pointer type; the element type here is a stand-in.
template class std::vector<StdVector140af0*>;
