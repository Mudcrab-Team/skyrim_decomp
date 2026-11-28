// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x10d2c0 StringAssignHelper10d2c0::Copy
// Adapted bodies: none
#include <cstring>
#include "StringAssignHelper10d2c0.h"

// guess: a captureless closure; the call does not read this.
// The community name table calls this a lambda operator() inside std::string::assign.
void StringAssignHelper10d2c0::Copy(char* a_dst, std::size_t a_count, const char* a_src) const
{
    std::memcpy(a_dst, a_src, a_count);
    a_dst[a_count] = 0;
}
