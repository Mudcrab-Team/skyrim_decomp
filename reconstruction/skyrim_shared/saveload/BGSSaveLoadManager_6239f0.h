// Source exposure: mixed (community-generated layout facts and the pinned image listing).
// Code origin: original partial class declaration; only accessed members are retained, and array types are included from the generated directory.
// BGSSaveLoadManager::loadedEntries, BGSSaveLoadManager::saveGameList, BGSSaveLoadManager::unk118, BGSSaveLoadManager::lastFileNameLength, BGSSaveLoadManager::unk2F0: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSSaveLoadManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// Function names, signatures, global names and unknown regions: GUESS(low); this is a partial model of the game class.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ReconstructedBGSSaveLoadManager {
#include "generated/crashlogger_pdb/types/BSTArray_RE__BGSSaveLoadManager__SaveEntry_424aa5fb.h"
#include "generated/crashlogger_pdb/types/BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14.h"
using SaveEntryArray = BSTArray_RE__BGSSaveLoadManager__SaveEntry_424aa5fb;
using SaveGameArray = BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14;
extern std::uint8_t unknownSaveState1908e3c;
extern std::uint8_t unknownSaveState20b5440;
extern std::uint32_t unknownSaveState1908e34;
class BGSSaveLoadManager {
public:
    SaveGameArray* Function6239f0();
    static std::uint8_t Function623460();
    static void Function623d90(std::uint8_t a_value);
    bool Function624d50() const;
    bool Function624780() const;
    void Function6233b0(std::uint8_t a_value);
    static std::uint32_t Function623450();
    std::uint8_t Function6247a0() const;
    void Function623910();
    void Function623930(SaveGameArray* a_list);
    std::uint8_t unknown000[0xE8];
    SaveEntryArray loadedEntries;
    SaveGameArray saveGameList;
    std::uint8_t unk118;
    std::uint8_t unknown119[0x248 - 0x119];
    std::uint16_t lastFileNameLength;
    std::uint8_t unknown24A[0x2F0 - 0x24A];
    std::uint8_t unk2F0;
};
static_assert(offsetof(BGSSaveLoadManager, loadedEntries) == 0xE8, "loaded-entry array offset");
static_assert(offsetof(BGSSaveLoadManager, saveGameList) == 0x100, "save-game array offset");
static_assert(offsetof(BGSSaveLoadManager, unk118) == 0x118, "save-state byte offset");
static_assert(offsetof(BGSSaveLoadManager, lastFileNameLength) == 0x248, "filename length offset");
static_assert(offsetof(BGSSaveLoadManager, unk2F0) == 0x2F0, "save-state byte offset");
}
