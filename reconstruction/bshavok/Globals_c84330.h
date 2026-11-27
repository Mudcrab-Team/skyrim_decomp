// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// RegisterHandlers: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct HandlerSet;
struct Registry;


typedef void (* HandlerFn)();

void Func00d3b380();
void Func00d3b420();
void Func00d3bd80();
void Func00daf8e0();

struct HandlerSet {
    HandlerFn m_pfnFirst;
    HandlerFn m_pfnSecond;
    HandlerFn m_pfnThird;
    HandlerFn m_pfnFourth;
    char m_cFlagA;
    char m_cFlagB;
};

struct Registry {
    void Func00cfbbe0(HandlerSet* apHandlers, int aiFirst, int aiSecond);
};

struct Globals
{
};
