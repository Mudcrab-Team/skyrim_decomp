// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x119b60 std::vector<VectorElement119b60*>::~vector
// CI hash: 0x119b60 ??1?$vector@PEAUVectorElement119b60@@V?$allocator@PEAUVectorElement119b60@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement119b60.h"

template class std::vector<VectorElement119b60*>;
