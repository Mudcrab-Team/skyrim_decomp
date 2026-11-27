// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func0084e4f0_cls: GUESS(low); placeholder name
// Func0084e4f0_cls::ReferenceInitialData_Initialize_CREATED: GUESS(low); placeholder name
#pragma once

unsigned int BGSNumericIDIndex_GetNumericID(void*);

struct Func0084e4f0_triple;


struct Func0084e4f0_triple
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

class Func0084e4f0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    Func0084e4f0_triple m_14;
    Func0084e4f0_triple m_20;
    unsigned char m_2c;
    void ReferenceInitialData_Initialize_CREATED(void* src);
};
