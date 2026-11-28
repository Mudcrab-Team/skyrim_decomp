// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1146a0 StringAppendHelper1146a0::CopyAndAppend
// Adapted bodies: none
#include <cstring>
#include "StringAppendHelper1146a0.h"

// guess: a captureless closure; the call does not read this.
// The community name table calls this a lambda operator() inside std::string::append.
void StringAppendHelper1146a0::CopyAndAppend(char* a_dst, const char* a_oldPtr, std::size_t a_oldSize, const char* a_src, std::size_t a_count) const
{
    std::memcpy(a_dst, a_oldPtr, a_oldSize);
    std::memcpy(a_dst + a_oldSize, a_src, a_count);
    a_dst[a_oldSize + a_count] = 0;
}
