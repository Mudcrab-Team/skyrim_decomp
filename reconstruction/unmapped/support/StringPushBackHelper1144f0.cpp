// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1144f0 StringPushBackHelper1144f0::CopyAndAppend
// Adapted bodies: none
#include <cstring>
#include "StringPushBackHelper1144f0.h"

// guess: a captureless closure; the call does not read this.
// Appends one character and a terminator after copying the old characters.
void StringPushBackHelper1144f0::CopyAndAppend(char* a_dst, const char* a_oldPtr, std::size_t a_oldSize, char a_ch) const
{
    std::memcpy(a_dst, a_oldPtr, a_oldSize);
    a_dst[a_oldSize] = a_ch;
    a_dst[a_oldSize + 1] = 0;
}
