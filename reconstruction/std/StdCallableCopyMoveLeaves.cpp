// Source exposure: mixed (pinned image and published community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original explicit instantiation of std::_Func_impl_no_alloc over stand-in callables.
// std::_Func_impl_no_alloc slots and callable sizes: OBSERVED
// StdCallableCopyMoveLeaves, CallableTable*, CallableObject*: GUESS(low) STANDIN; callable contents and signatures unknown.
// Adapted bodies: none
// 0x576140 std::_Func_impl_no_alloc<CallableTable18eef70, void>::_Copy
// 0x576230 std::_Func_impl_no_alloc<CallableTable18eef70, void>::_Move
// CI hash: 0x576140 ?_Copy@?$_Func_impl_no_alloc@UCallableTable18eef70@@X$$V@std@@EEBAPEAV?$_Func_base@X$$V@2@PEAX@Z
// CI hash: 0x576230 ?_Move@?$_Func_impl_no_alloc@UCallableTable18eef70@@X$$V@std@@EEAAPEAV?$_Func_base@X$$V@2@PEAX@Z
#include "StdCallableCopyMoveLeaves.h"

// PDB note: the destructor annotation conflicts with RTTI-owned primary copy/move slots; the complete slot bodies and table binding are compared.
template class std::_Func_impl_no_alloc<CallableTable18eef70, void>;
