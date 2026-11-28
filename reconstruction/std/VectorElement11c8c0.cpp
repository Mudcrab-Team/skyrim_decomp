// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x11c8c0 std::vector<VectorElement11c8c0*>::~vector
// CI hash: 0x11c8c0 ??1?$vector@PEAUVectorElement11c8c0@@V?$allocator@PEAUVectorElement11c8c0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement11c8c0.h"

template class std::vector<VectorElement11c8c0*>;
