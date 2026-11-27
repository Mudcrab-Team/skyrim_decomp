// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00d3cef0: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

extern void Func00d3c440(int a, int b, int c, int d);
extern void Func00d3cc00(void*, void*, int, void*);

struct Conversion;
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
struct Registry
{
    void Func00cfbbe0(Conversion*, int, int);
};
void Func00d3c400();
void Func00d3cfc0();
void FlipAndDispatchCollector();
void Func00d3ac80();
void CreateD3C380Obj();
void Func00d3c440();
void Func00d3cc00();
void Func00daf8e0();

struct Globals
{
};
