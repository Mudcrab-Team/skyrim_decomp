// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// StructArrayImplementation: CRASHLOGGER_PDB(59818@2026.10.24)
// StructArrayImplementation::reserve: CRASHLOGGER_PDB(59818@2026.10.24)
// vslot_0_, vslot_1_, vslot_2_: GUESS(low); placeholder name
#pragma once

struct ShapeEntry;
struct ShapeItem;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ShapeItem
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual void vslot_2_();
    virtual void v09(int arg);
};

struct ShapeEntry
{
    int unk00;
    ShapeItem* m_pInventoryEntryData;  // +0x4
};

class StructArrayImplementation
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ShapeEntry* m_entries;  // +0xc
    int m_uiItemCount;      // +0x10

    void reserve(int arg);
};
