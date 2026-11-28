// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in pointer type
// SPDX-License-Identifier: CC0-1.0
// 0x116b00 std::vector<VectorElement116b00*>::~vector
// CI hash: 0x116b00 ??1?$vector@PEAUVectorElement116b00@@V?$allocator@PEAUVectorElement116b00@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "VectorElement116b00.h"

template class std::vector<VectorElement116b00*>;
