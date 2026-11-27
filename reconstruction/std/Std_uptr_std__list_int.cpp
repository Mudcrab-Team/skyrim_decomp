// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0xf88fc0 std::list<>::vector_deleting_dtor
// CI hash: 0xf88fc0 ??_E?$list@HV?$allocator@H@std@@@std@@QEAAPEAXI@Z
#include "Std_uptr_std__list_int.h"

template class std::unique_ptr<std::list<int>>;
template class std::unique_ptr<std::list<int>[]>;
