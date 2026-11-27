// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x10caa0 std::basic_string<>::operator_
// 0x10cad0 std::basic_string<>::_Tidy_deallocate
// 0x10d430 std::allocator<>::deallocate
// 0x10ed20 std::_Deallocate<>
// CI hash: 0x10caa0 ??4?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV01@AEBV01@@Z
// CI hash: 0x10cad0 ?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ
// CI hash: 0x10d430 ?deallocate@?$allocator@D@std@@QEAAXQEAD_K@Z
// CI hash: 0x10ed20 ??$_Deallocate@$0BA@$0A@@std@@YAXPEAX_K@Z
#include "Std_array4_std__string_10caa0.h"

template class std::array<std::string, 4>;
