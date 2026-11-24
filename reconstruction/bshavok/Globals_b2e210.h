// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkDynamicClassNameRegistry: CRASHLOGGER_PDB(59818@2026.10.24)
// hkDynamicClassNameRegistry::registerList: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

class hkDynamicClassNameRegistry
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void add(const char* pcName, int iFlags);

    void registerList(const char* const* ppcNames);
};

struct Globals
{
};
