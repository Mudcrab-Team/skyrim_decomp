// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkDataClassNative: CRASHLOGGER_PDB(59818@2026.10.24)
// hkDataClassNative::getParent: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

namespace fnv_00dbb940 {
struct D481D0Class;
struct Func00d46d50_s;
struct Func00dbb940_VirtualClass;


struct D481D0Class
{
    char const* getName() const;
};

struct Func00d46d50_s
{
    D481D0Class* Func00d46d50();
};

struct Func00dbb940_VirtualClass
{
    virtual void Func00dbb940_0() = 0;
    virtual void Func00dbb940_1() = 0;
    virtual void Func00dbb940_2() = 0;
    virtual void Func00dbb940_3() = 0;
    virtual void Func00dbb940_4() = 0;
    virtual void Func00dbb940_5() = 0;
    virtual void Func00dbb940_6() = 0;
    virtual void Func00dbb940_7() = 0;
    virtual void Func00dbb940_8() = 0;
    virtual int Func00dbb940_9(char const* name) = 0;
};

struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    Func00d46d50_s* m_0C;
    Func00dbb940_VirtualClass* m_10;

    int getParent();
};

}

struct Globals
{
};
