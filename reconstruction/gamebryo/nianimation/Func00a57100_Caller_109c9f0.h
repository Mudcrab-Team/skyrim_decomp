// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00a57100_Caller: GUESS(low); placeholder name
// Func00a57100_Caller::Func00a57100: GUESS(low); placeholder name
#pragma once

struct BaseFake;
struct NiFixedString;
struct NiStream;
struct StreamVTable;

class NiFixedString
{
  public:
    const char* data;
};

class NiStream
{
  public:
    char padding[0xd8];
    unsigned int version;
    void ReadFixedString(NiFixedString&);
    void ReadStringTableEntry(NiFixedString&);
};


struct BaseFake
{
    bool RegisterInterpolatorStreamables(NiStream&);
};
struct StreamVTable
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(void*);
};
struct Func00a57100_Caller
{
    bool Func00a57100(NiStream&);
};
