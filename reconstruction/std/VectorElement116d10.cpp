// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x116d10 std::vector<VectorElement116d10*>::~vector
// CI hash: 0x116d10 ??1?$vector@PEAUVectorElement116d10@@V?$allocator@PEAUVectorElement116d10@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement116d10.h"

template class std::vector<VectorElement116d10*>;
