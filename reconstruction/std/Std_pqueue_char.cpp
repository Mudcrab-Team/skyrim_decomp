// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x427780 std::vector<>::~vector<>
// 0x15a3ed0 std::vector<>::_Change_array
// CI hash: 0x427780 ??1?$vector@DV?$allocator@D@std@@@std@@QEAA@XZ
// CI hash: 0x15a3ed0 ?_Change_array@?$vector@DV?$allocator@D@std@@@std@@AEAAXQEAD_K1@Z
#include "Std_pqueue_char.h"

template class std::priority_queue<char>;
