// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00e29250: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct E29250Matrix3;
struct E29250Matrix6;


struct E29250Matrix3
{
    float m_kColumn0[4];
    float m_kColumn1[4];
    float m_kColumn2[4];

    void SetFromMatrix(const E29250Matrix3& s);
};

struct E29250Matrix6
{
    E29250Matrix3 m_iUnknownValue2[2][2];
};

struct Globals
{
};
