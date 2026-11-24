// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x6239f0 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function6239f0
// 0x623460 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function623460
// 0x623d90 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function623d90
// 0x624d50 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function624d50
// 0x624780 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function624780
// 0x6233b0 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function6233b0
// 0x623450 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function623450
// 0x6247a0 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function6247a0
// 0x623910 ReconstructedBGSSaveLoadManager::BGSSaveLoadManager::Function623910
#include "BGSSaveLoadManager_6239f0.h"





namespace ReconstructedBGSSaveLoadManager {

// Return the save-game list.
BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14* BGSSaveLoadManager::Function6239f0()
{
    return &saveGameList;
}

// Read the shared save-state byte.
std::uint8_t BGSSaveLoadManager::Function623460()
{
    return unknownSaveState1908e3c;
}

// Set the shared save-state byte.
void BGSSaveLoadManager::Function623d90(std::uint8_t a_value)
{
    unknownSaveState20b5440 = a_value;
}

// Test whether the last filename has a nonzero length.
bool BGSSaveLoadManager::Function624d50() const
{
    return lastFileNameLength != 0;
}

// Test whether there are no loaded save entries.
bool BGSSaveLoadManager::Function624780() const
{
    return loadedEntries._size == 0;
}

// Set the unidentified save-manager state byte.
void BGSSaveLoadManager::Function6233b0(std::uint8_t a_value)
{
    unk2F0 = a_value;
}

// Read the shared save-state word.
std::uint32_t BGSSaveLoadManager::Function623450()
{
    return unknownSaveState1908e34;
}

// Read the state byte following the save-game list.
std::uint8_t BGSSaveLoadManager::Function6247a0() const
{
    return unk118;
}

// Forward the save-game list to the shared operation.
void BGSSaveLoadManager::Function623910()
{
    Function623930(&saveGameList);
}

}
