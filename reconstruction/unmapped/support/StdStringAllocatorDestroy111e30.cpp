// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::allocator<std::string>::destroy
// SPDX-License-Identifier: CC0-1.0
// 0x111e30 std::allocator<std::string>::destroy
// CI hash: 0x111e30 ??$destroy@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QEAAXQEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z
// Adapted bodies: none.
#include "StdStringAllocatorDestroy111e30.h"

template void std::allocator<std::string>::destroy<std::string>(std::string* const);
