// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Script, Script::ClearCachedValues: CRASHLOGGER_PDB(59818@2026.10.24)
// gScriptCache0, gScriptCache1, gScriptCache2, gScriptCache3, gScriptCache4, gScriptCache5, gScriptCache6, gScriptCache7, gScriptCache8: GUESS
#pragma once

#include <cstdint>

extern void* gScriptCache0;
extern void* gScriptCache1;
extern std::uint32_t gScriptCache2;
extern void* gScriptCache3;
extern void* gScriptCache4;
extern void* gScriptCache5;
extern void* gScriptCache6;
extern void* gScriptCache7;
extern std::uint32_t gScriptCache8;

class Script
{
  public:
    static void ClearCachedValues();
};
