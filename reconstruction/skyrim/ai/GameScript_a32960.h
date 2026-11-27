// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// GameScript: CRASHLOGGER_PDB(59818@2026.10.24)
// GameScript::CleanupAllBindings: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

namespace fnv_00982310 {
struct BGSLoadFormBuffer;


struct BGSLoadFormBuffer;
struct TESNPC
{
    void Revert(BGSLoadFormBuffer*);
};
struct GameScript
{
    void Func0097f390();
    void UpdatePointer();
    void Func0097d9d0();
    void UpdateActorValues();
    void CleanupAllBindings(BGSLoadFormBuffer* apLoadGameBuffer);
};
}
