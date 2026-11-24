// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// bhkEntity, bhkEntity::~bhkEntity: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
// bhkEntityOwner, m_2b0, padding_00_2b0_: GUESS(low); placeholder name
#pragma once

struct Func00c876a0_holder
{
    virtual ~Func00c876a0_holder();
    void Func00c876a0();
};

struct hkReferencedObject
{
    void removeReference();
};

struct bhkEntityOwner
{
    char padding_00_2b0_[0x2b0];
    hkReferencedObject* m_2b0;
};


extern int Data012681fc;
struct bhkEntity : Func00c876a0_holder
{
    void* m0;
    bhkEntityOwner* m4;
    void* m8;
    bhkEntity();
    ~bhkEntity();
};

struct Globals
{
};
