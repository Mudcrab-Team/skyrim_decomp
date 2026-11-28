// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x10cee0 std::vector<VectorElement10cee0*>::~vector
// CI hash: 0x10cee0 ??1?$vector@PEAUVectorElement10cee0@@V?$allocator@PEAUVectorElement10cee0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement10cee0.h"

template class std::vector<VectorElement10cee0*>;
