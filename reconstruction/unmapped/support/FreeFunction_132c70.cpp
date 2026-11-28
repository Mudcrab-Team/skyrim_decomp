// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x132c70 Function132c70
// Adapted bodies: none
#include "FreeFunction_132c70.h"

// Forwards unpacked reference arguments to an indirect callback pointer.
void Function132c70(Callback132c70* a_fn, const std::uint64_t& a_arg1, const std::uint32_t& a_arg2, const void* a_arg3, const std::uint32_t& a_arg4)
{
    (*a_fn)(a_arg1, a_arg2, a_arg3, a_arg4);
}
