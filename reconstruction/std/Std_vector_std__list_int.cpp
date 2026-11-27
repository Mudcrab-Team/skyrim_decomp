// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x582230 std::_Uninitialized_backout_al<>::~_Uninitialized_backout_al<>
// 0x585880 std::vector<>::_Tidy
// CI hash: 0x582230 ??1?$_Uninitialized_backout_al@PEAV?$list@HV?$allocator@H@std@@@std@@V?$allocator@V?$list@HV?$allocator@H@std@@@std@@@2@@std@@QEAA@XZ
// CI hash: 0x585880 ?_Tidy@?$vector@V?$list@HV?$allocator@H@std@@@std@@V?$allocator@V?$list@HV?$allocator@H@std@@@std@@@2@@std@@AEAAXXZ
#include "Std_vector_std__list_int.h"

template class std::vector<std::list<int>>;
