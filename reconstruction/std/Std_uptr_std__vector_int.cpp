// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x14e630 std::vector<>::vector_deleting_dtor
// CI hash: 0x14e630 ??_E?$vector@HV?$allocator@H@std@@@std@@QEAAPEAXI@Z
#include "Std_uptr_std__vector_int.h"

template class std::unique_ptr<std::vector<int>>;
template class std::unique_ptr<std::vector<int>[]>;
