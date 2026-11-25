// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00d2b360: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct PathHelper;


struct PathHelper {
    char* m_data;

    void Func00d61c10(const char* s);
    void ReplaceChar(char from, char to, int all);
    void Func00d62190(const char* from, const char* to, int all);
    int Func00d61560(const char* s);
    void RemoveFront(int count);
};

struct Globals
{
};
