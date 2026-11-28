// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x122c80 Function122c80
// Adapted bodies: none
#include "FreeFunction_122c80.h"

// Compares two sized byte buffers for exact equality.
bool Function122c80(const char* a_lhs, std::size_t a_lhsLen, const char* a_rhs, std::size_t a_rhsLen)
{
    return a_lhsLen == a_rhsLen && std::memcmp(a_lhs, a_rhs, a_lhsLen) == 0;
}
