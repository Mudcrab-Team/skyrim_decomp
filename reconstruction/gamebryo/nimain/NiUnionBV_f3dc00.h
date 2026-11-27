// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// E9E8C0Array: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// E9E8C0Array::Func00e9e8c0: GUESS(low); placeholder name
// NiUnionBV: GUESS(low); placeholder name
#pragma once

struct E9E8C0Item;


struct E9E8C0Item
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual bool IsDifferent(E9E8C0Item* pkOther);
};

struct E9E8C0ItemList
{
    E9E8C0Item** m_ppkBase;
    unsigned short m_usUnk04;
    unsigned short m_usSize;

    E9E8C0Item*& GetAt(unsigned int ui)
    {
        return m_ppkBase[ui];
    }
    unsigned short GetSize() const
    {
        return m_usSize;
    }
};

class E9E8C0Array
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int GetType();

    bool Func00e9e8c0(E9E8C0Array* pkOther);

  protected:
    int m_unk04;
    E9E8C0ItemList m_kUnsortedGeometryList;
};

struct NiUnionBV
{
};
