// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x11a060 std::vector<VectorElement11a060*>::~vector
// CI hash: 0x11a060 ??1?$vector@PEAUVectorElement11a060@@V?$allocator@PEAUVectorElement11a060@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement11a060.h"

template class std::vector<VectorElement11a060*>;
