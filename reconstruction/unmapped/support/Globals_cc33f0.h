// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func009c9fd0: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

namespace f3m_009c9fd0 {
namespace task0999 {
struct Funcs;
struct Registry;

struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};


struct Funcs {void* p1; void* p2; void* p3; void* p4; unsigned char b1,b2;};
void Func009c9f80(Funcs*);
struct Registry { void Func00985c10(const Funcs&,int,int); };
}
}

struct Globals
{
};
