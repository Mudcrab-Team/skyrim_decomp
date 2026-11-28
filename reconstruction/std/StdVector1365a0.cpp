// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; explicit instantiation of std::vector from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1365a0 std::vector<unsigned int>::_Change_array
// CI hash: 0x1365a0 ?_Change_array@?$vector@IV?$allocator@I@std@@@std@@AEAAXQEAI_K1@Z
// Adapted bodies: none
#include "StdVector1365a0.h"

// PDB: the CrashLogger PDB marks this address FID_conflict:_Change_array; the element type here follows the compared instantiation.
template class std::vector<std::uint32_t>;
