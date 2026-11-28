// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over std::function with a stand-in argument
// SPDX-License-Identifier: CC0-1.0
// 0x131c50 std::vector<>::_Change_array
// CI hash: 0x131c50 ?_Change_array@?$vector@V?$function@$$A6AXPEAUStdFuncVec131c50@@@Z@std@@V?$allocator@V?$function@$$A6AXPEAUStdFuncVec131c50@@@Z@std@@@2@@std@@AEAAXQEAV?$function@$$A6AXPEAUStdFuncVec131c50@@@Z@2@_K1@Z
// Adapted bodies: none
#include "StdFuncVec131c50.h"

template class std::vector<std::function<void(StdFuncVec131c50*)>>;
