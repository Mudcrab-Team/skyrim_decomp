// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// D06D50Finder: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// D06D50Finder::FindClass: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_: GUESS(low); placeholder name
#pragma once

struct D06D50Class;
struct D06D50Object;
struct D06D50Registry;



struct D06D50Class;

struct D06D50Object
{
    virtual void unk00();
    virtual const D06D50Class* GetClassType() const;
};

struct D06D50Registry
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual const D06D50Class* GetClassFromName(const D06D50Object* object) const;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct D06D50Finder
{
  public:
    char padding_0_[24];
    const D06D50Registry *m_registry;
    const D06D50Class* FindClass(const D06D50Object* object) const;
};
