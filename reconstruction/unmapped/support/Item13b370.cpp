// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; explicit instantiation of a standard library template over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// 0x13b370 std::vector<Item13b370>::_Destroy
// CI hash: 0x13b370 ?_Destroy@?$vector@UItem13b370@@V?$allocator@UItem13b370@@@std@@@std@@AEAAXPEAUItem13b370@@0@Z
// Adapted bodies: none
#include "Item13b370.h"

template void std::vector<Item13b370>::_Destroy(Item13b370*, Item13b370*);
