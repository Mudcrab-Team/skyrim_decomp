// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; explicit instantiation from standard headers, selected from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13a140 std::basic_string<char>::find_first_of
// CI hash: 0x13a140 ?find_first_of@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBA_KQEBD_K@Z
// Adapted bodies: none
#include "Func_13a140.h"

#include <cstddef>
#include <string>

template std::size_t std::basic_string<char>::find_first_of(const char*, std::size_t) const noexcept;
