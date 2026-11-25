// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpCharacterStateManager: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpCharacterStateManager::Routine140AB9F10: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct hkpCharacterStateManager
{
  public:
    char padding_0_[16];
    hkReferencedObject *m_states[32];
    void Routine140AB9F10(hkReferencedObject* object, int index);
};

struct Globals
{
};
