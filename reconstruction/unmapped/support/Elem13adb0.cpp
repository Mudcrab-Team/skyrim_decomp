// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; explicit instantiation of a standard library template over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// 0x13adb0 std::vector<Elem13adb0>::~vector
// CI hash: 0x13adb0 ??1?$vector@UElem13adb0@@V?$allocator@UElem13adb0@@@std@@@std@@QEAA@XZ
// Adapted bodies: none
#include "Elem13adb0.h"

template std::vector<Elem13adb0>::~vector();
