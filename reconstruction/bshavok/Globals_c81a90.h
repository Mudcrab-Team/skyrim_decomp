// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpSphereSphereAgent: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpSphereSphereAgent::Routine140BA59F0: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

struct S_00d3f660_Owner;


struct S_00d3f660_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release(unsigned short id, void* arg);
};

struct hkpSphereSphereAgent
{
    virtual ~hkpSphereSphereAgent();
    int unk4;
    S_00d3f660_Owner* unk8;
    unsigned short unkC;
    void Routine140BA59F0(void* arg);
};

struct Globals
{
};
