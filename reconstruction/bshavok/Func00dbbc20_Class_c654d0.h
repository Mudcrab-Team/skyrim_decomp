// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00dbbc20_Class: GUESS(low); placeholder name
// Func00dbbc20_Class::Func00dbbc20: GUESS(low); placeholder name
#pragma once

namespace fnv_00dbbc20 {
struct D481D0Class;


struct D481D0Class
{
    virtual int Func00dbbc20_1();
    virtual int Func00dbbc20_2();
    virtual int Func00dbbc20_3();
    virtual int Func00dbbc20_4();
    virtual int Func00dbbc20_5();
    virtual int Func00dbbc20_6();
    virtual int Func00dbbc20_7();
    virtual int Func00dbbc20_8();
    virtual int Func00dbbc20_9();
    virtual int Func00dbbc20_10(char const* name);

    char const* getName() const;
};

struct Func00dbbc20_Class : D481D0Class
{
    int m_04;
    int m_08;
    D481D0Class* m_0C;
    void* m_10;
    int m_14;
    int m_18;
    int m_1C;
    D481D0Class* m_20;

    int Func00dbbc20();
};

}
