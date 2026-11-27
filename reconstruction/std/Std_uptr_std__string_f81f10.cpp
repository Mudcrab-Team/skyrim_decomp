// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0xf81f10 std::basic_string<>::vector_deleting_dtor
// CI hash: 0xf81f10 ??_E?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAPEAXI@Z
#include "Std_uptr_std__string_f81f10.h"

template class std::unique_ptr<std::string>;
template class std::unique_ptr<std::string[]>;
