// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x116bb0 std::vector<VectorElement116bb0*>::~vector
// CI hash: 0x116bb0 ??1?$vector@PEAUVectorElement116bb0@@V?$allocator@PEAUVectorElement116bb0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement116bb0.h"

template class std::vector<VectorElement116bb0*>;
