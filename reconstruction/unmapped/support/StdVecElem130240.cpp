// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in 4-byte element
// SPDX-License-Identifier: CC0-1.0
// 0x130240 std::vector<>::_Change_array
// CI hash: 0x130240 ?_Change_array@?$vector@UStdVecElem130240@@V?$allocator@UStdVecElem130240@@@std@@@std@@AEAAXQEAUStdVecElem130240@@_K1@Z
// Adapted bodies: none
#include "StdVecElem130240.h"

// The community name table calls this _Change_array (a hint, not proof of the element type).
template class std::vector<StdVecElem130240>;
