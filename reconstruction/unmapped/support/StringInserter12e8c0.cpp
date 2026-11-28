// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x12e8c0 StringInserter12e8c0::InsertComma
// Adapted bodies: none
#include "StringInserter12e8c0.h"

// Copies a string buffer into new storage while inserting a single comma at the given offset.
// guess: a captureless closure; the call does not read this.
void StringInserter12e8c0::InsertComma(char* a_newPtr, const char* a_oldPtr, std::size_t a_oldSize, std::size_t a_off)
{
    std::char_traits<char>::copy(a_newPtr, a_oldPtr, a_off);
    std::char_traits<char>::assign(a_newPtr + a_off, 1, ',');
    std::char_traits<char>::copy(a_newPtr + a_off + 1, a_oldPtr + a_off, a_oldSize - a_off + 1);
}
