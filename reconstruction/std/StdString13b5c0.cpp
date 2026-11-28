// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; explicit instantiation of std::basic_string from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13b5c0 std::basic_string<char>::erase
// CI hash: 0x13b5c0 ?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K@Z
// Adapted bodies: none
#include "StdString13b5c0.h"

template class std::basic_string<char>;
