// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x10d550 std::allocator<>::deallocate
// 0x117850 std::_Default_allocator_traits<>::deallocate
// CI hash: 0x10d550 ?deallocate@?$allocator@PEAUP12@@@std@@QEAAXQEAPEAUP12@@_K@Z
// CI hash: 0x117850 ?deallocate@?$_Default_allocator_traits@V?$allocator@U_Container_proxy@std@@@std@@@std@@SAXAEAV?$allocator@U_Container_proxy@std@@@2@QEAU_Container_proxy@2@_K@Z
#include "Std_deque_P12_10d550.h"

template class std::deque<P12>;
