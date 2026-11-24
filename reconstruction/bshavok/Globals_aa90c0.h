// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00cf6330: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct Container;
struct Shape;



struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Shape;

struct Container
{
    __declspec(nothrow) int Func00d46f70() const;
    __declspec(nothrow) const Shape* Func00d46f80(int i) const;
};

__declspec(nothrow) hkBool GetFlagByState(const Shape* s);

struct Globals
{
};
