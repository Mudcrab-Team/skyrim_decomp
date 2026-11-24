// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkObjectResource: CRASHLOGGER_PDB(59818@2026.10.24)
// hkObjectResource::Routine140BE4200: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

namespace fnv_00e05030 {
struct D481D0Class;
struct Func00d46d40_s;
struct Registry;

struct D481D0Class
{
    const char* getName() const;
};

struct hkBoolD46D
{
    char m_cBooleanValue;
    hkBoolD46D(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};


struct hkBool
{
    char m_cBooleanValue;
    hkBool();
};

struct Func00d46d40_s
{
    const char* Func00d46d40();
    hkBool Func00d46d80(Func00d46d40_s* other);
};

struct Registry
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual Func00d46d40_s* GetClassByName(const char* name);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct hkObjectResource
{
  public:
    char padding_0_[16];
    void *unk08;
    D481D0Class *unk0C;
    Registry *unk10;
    void* Routine140BE4200(const char* name, hkBool b);
};

}

struct Globals
{
};
