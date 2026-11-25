// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x110870 std::basic_string<>::compare
// 0x111dc0 std::_Traits_compare<>
// 0x1225d0 std::operator__<>
// CI hash: 0x110870 ?compare@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBAHAEBV12@@Z
// CI hash: 0x111dc0 ??$_Traits_compare@U?$char_traits@D@std@@@std@@YAHQEBD_K01@Z
// CI hash: 0x1225d0 ??$?8DU?$char_traits@D@std@@V?$allocator@D@1@@std@@YA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@0@Z
#include "Std_flist_std__string_110870.h"

template class std::forward_list<std::string>;
