// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00d5a320: GUESS(low); placeholder name
// Func00d5a320::AssignReference: GUESS(low); placeholder name
// Func00d5a320::m_88, padding_00_88_: GUESS(low); placeholder name
#pragma once

struct RefObj;


struct RefObj { void RetainReference(); void removeReference(); };
struct Func00d5a320 {
    char padding_00_88_[0x88];
    RefObj* m_88;
    void Func00d59f40();
    void AssignReference(RefObj* p, bool b);
};
