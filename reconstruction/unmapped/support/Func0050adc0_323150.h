// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func0050adc0, Func0050adc0::~Func0050adc0: GUESS(low); placeholder name
#pragma once

extern "C" void Func00c24b70(const char*,...);

namespace f3m_0050adc0 {
namespace task0307 {

struct Func00455a70 {
    virtual void FirstSlot();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~Func00455a70();
};
struct Func0045bd00 {
    virtual void SecondSlot();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~Func0045bd00();
};
struct Func0050adc0 : Func00455a70, Func0045bd00 {
    void Func00c24b70();
    ~Func0050adc0();
};
}
}
