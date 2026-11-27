// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x13e2f0 std::vector<>::operator_
// 0x58ed20 std::_Hash<>::~_Hash<>
// CI hash: 0x13e2f0 ??4?$vector@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@QEBDUP16@@@std@@@std@@@std@@@std@@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@QEBDUP16@@@std@@@std@@@std@@@std@@@2@@std@@QEAAAEAV01@$$QEAV01@@Z
// CI hash: 0x58ed20 ??1?$_Hash@V?$_Umap_traits@PEBDUP16@@V?$_Uhash_compare@PEBDU?$hash@PEBD@std@@U?$equal_to@PEBD@2@@std@@V?$allocator@U?$pair@QEBDUP16@@@std@@@3@$0A@@std@@@std@@QEAA@XZ
#include "Std_umap_const_charptr_P16.h"

template class std::unordered_map<const char*, P16>;
