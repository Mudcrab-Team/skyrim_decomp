// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x116ca0 std::vector<VectorElement116ca0*>::~vector
// CI hash: 0x116ca0 ??1?$vector@PEAUVectorElement116ca0@@V?$allocator@PEAUVectorElement116ca0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement116ca0.h"

template class std::vector<VectorElement116ca0*>;
