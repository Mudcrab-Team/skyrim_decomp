// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x132cd0 Function132cd0
// Adapted bodies: none
#include "FreeFunction_132cd0.h"

// Forwards unpacked reference arguments to an indirect callback pointer.
void Function132cd0(Callback132cd0* a_fn, const std::uint64_t& a_arg1, const std::uint32_t& a_arg2, const void* a_arg3, const std::uint32_t& a_arg4)
{
    (*a_fn)(a_arg1, a_arg2, a_arg3, a_arg4);
}
