// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// CD4AF0Matrix3: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// CD4AF0Matrix3::Func00cd4af0: GUESS(low); placeholder name
#pragma once

struct CD4AF0Bool
{
    char m_cBooleanValue;

    CD4AF0Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct CD4AF0Vector4
{
    float x;
    float y;
    float z;
    float w;

    CD4AF0Bool IsStreamValid() const;
};

struct CD4AF0Matrix3
{
    CD4AF0Vector4 m_kColumn0;
    CD4AF0Vector4 m_kColumn1;
    CD4AF0Vector4 m_kColumn2;

    CD4AF0Bool Func00cd4af0() const;
};
