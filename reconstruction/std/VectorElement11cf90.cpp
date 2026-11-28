// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x11cf90 std::vector<VectorElement11cf90*>::~vector
// CI hash: 0x11cf90 ??1?$vector@PEAUVectorElement11cf90@@V?$allocator@PEAUVectorElement11cf90@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement11cf90.h"

template class std::vector<VectorElement11cf90*>;
