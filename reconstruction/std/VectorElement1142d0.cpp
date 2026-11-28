// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x1142d0 std::vector<VectorElement1142d0*>::~vector
// CI hash: 0x1142d0 ??1?$vector@PEAUVectorElement1142d0@@V?$allocator@PEAUVectorElement1142d0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement1142d0.h"

template class std::vector<VectorElement1142d0*>;
