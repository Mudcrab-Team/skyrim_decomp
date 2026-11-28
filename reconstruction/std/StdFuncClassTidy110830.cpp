// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Func_class over a stand-in argument type
// SPDX-License-Identifier: CC0-1.0
// 0x110830 std::_Func_class<>::_Tidy
// CI hash: 0x110830 ?_Tidy@?$_Func_class@XPEAUStdFuncClassTidy110830@@@std@@IEAAXXZ
// Adapted bodies: none
#include "StdFuncClassTidy110830.h"

// One of several identical copies in the image; which signature each belongs to is not established.
template class std::_Func_class<void, StdFuncClassTidy110830*>;
