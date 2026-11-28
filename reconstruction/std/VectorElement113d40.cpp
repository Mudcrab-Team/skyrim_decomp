// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x113d40 std::vector<VectorElement113d40*>::~vector
// CI hash: 0x113d40 ??1?$vector@PEAUVectorElement113d40@@V?$allocator@PEAUVectorElement113d40@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement113d40.h"

template class std::vector<VectorElement113d40*>;
