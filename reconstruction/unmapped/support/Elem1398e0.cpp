// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; explicit instantiation of a standard library template over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// 0x1398e0 std::vector<Elem1398e0>::~vector
// CI hash: 0x1398e0 ??1?$vector@UElem1398e0@@V?$allocator@UElem1398e0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "Elem1398e0.h"

template std::vector<Elem1398e0>::~vector();
