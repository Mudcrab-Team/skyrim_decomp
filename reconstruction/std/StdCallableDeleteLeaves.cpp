// Source exposure: mixed (pinned image and published community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original explicit instantiation of std::_Func_impl_no_alloc over stand-in callables.
// std::_Func_impl_no_alloc slots and callable sizes: OBSERVED
// StdCallableDeleteLeaves, CallableTable*, CallableObject*: GUESS(low) STANDIN; callable contents and signatures unknown.
// Adapted bodies: none
// 0x576170 std::_Func_impl_no_alloc<CallableObject576170, void>::_Delete_this
// CI hash: 0x576170 ?_Delete_this@?$_Func_impl_no_alloc@UCallableObject576170@@X$$V@std@@EEAAX_N@Z
#include "StdCallableDeleteLeaves.h"

struct CallableObject576170 : StdCallableState<8> {};
template class std::_Func_impl_no_alloc<CallableObject576170, void>;
