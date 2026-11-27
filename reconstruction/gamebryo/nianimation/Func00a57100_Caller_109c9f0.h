// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00a57100_Caller: GUESS(low); placeholder name
// Func00a57100_Caller::Func00a57100: GUESS(low); placeholder name
// Func00a57100_Caller::RegisterInterpolatorStreamables, m_10, padding_00_10_, NiStream::f0, f1, f2, f3, f4, f5, f6, f7, f8, padding: GUESS(low); placeholder name
#pragma once

struct NiFixedString;
struct NiStream;

class NiFixedString
{
  public:
    const char* data;
};

class NiStream
{
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(void*);
    char padding[0xd0];
    unsigned int version;
    void ReadFixedString(NiFixedString&);
    void ReadStringTableEntry(NiFixedString&);
};


struct Func00a57100_Caller
{
    char padding_00_10_[0x10];
    char m_10;
    bool RegisterInterpolatorStreamables(NiStream&);
    bool Func00a57100(NiStream&);
};
