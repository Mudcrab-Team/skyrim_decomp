// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpPhantom: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpPhantom::Routine140A913B0: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct Func00d07910_elem;


class hkpPhantom;

class Func00d07910_elem
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(hkpPhantom* owner);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkpPhantom
{
  public:
    char padding_0_[224];
    Func00d07910_elem **m_98;
    int m_9C;
    void Routine140A913B0();
};

struct Globals
{
};
