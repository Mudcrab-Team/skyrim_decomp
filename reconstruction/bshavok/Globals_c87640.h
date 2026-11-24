// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00d2e970: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
// FlipCollector, v0, v1, v2, flip, collector: GUESS(low); placeholder name
#pragma once

extern "C" void Func00d312f0(void*, void*, void*, void*);


// Collector subclass whose constructor stores the vftable pointer the function writes;
// the virtuals are only declared because the function never calls them.
struct FlipCollector
{
    FlipCollector(void* apCollector) : flip(0), collector(apCollector) {}
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char flip;
    void* collector;
};

struct Globals
{
};
