// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// RegisterAll: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct CBFC10Registry;


class CBFC10Bool
{
  public:
    CBFC10Bool(bool b)
    {
        m_cBool = (char)b;
    }
    char m_cBool;
};
class CBFC10Registry
{
  public:
    void Set(CBFC10Bool bLocked);
};
void CBFC10RegisterA(CBFC10Registry* pkRegistry);
void CBFC10RegisterB(CBFC10Registry* pkRegistry);
void CBFC10RegisterC(CBFC10Registry* pkRegistry);
void CBFC10RegisterD(CBFC10Registry* pkRegistry);
void CBFC10RegisterE(CBFC10Registry* pkRegistry);

struct Globals
{
};
