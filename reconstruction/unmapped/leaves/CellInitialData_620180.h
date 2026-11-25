// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadInitialData.cpp:75
// CellInitialData::Initialize: SIBLING(fo4-private@1b765c70, author-permission)
// CellInitialData, ExteriorCellInitialDataChar, CellInitialData::iWorldSpaceID, CellInitialData::iCellX, CellInitialData::iCellY, CellInitialData::iDetachTime, ExteriorCellInitialDataChar::cCellX, ExteriorCellInitialDataChar::cCellY, ExteriorCellInitialDataChar::iDetachTime, ExteriorCellInitialDataChar::sWorldSpaceIDIndex: GUESS(low); the names are the ones the sibling body uses
// BGSSaveLoadGame, pSaveLoadGame, WorldspaceFormIDMap, FormIDMap, FormIDMap::GetFormID: GUESS(low); the names are the ones the sibling body uses, the layout comes from the listing
// BGSSaveLoadGame::unknown00, FormIDMap::unknown00: GUESS(low)
#pragma once

#include <cstdint>

struct ExteriorCellInitialDataChar
{
    std::uint16_t sWorldSpaceIDIndex;  // 00
    std::int8_t cCellX;                // 02
    std::int8_t cCellY;                // 03
    std::int32_t iDetachTime;          // 04
};

struct FormIDMap
{
    std::uint32_t GetFormID(std::uint16_t a_index);

    std::uint8_t unknown00[0x10];  // 00
};

struct BGSSaveLoadGame
{
    std::uint8_t unknown00[0x30];  // 00
    FormIDMap WorldspaceFormIDMap; // 30
};

extern BGSSaveLoadGame* pSaveLoadGame;

struct CellInitialData
{
    void Initialize(ExteriorCellInitialDataChar* a_data);

    std::uint32_t iWorldSpaceID;  // 00
    std::int32_t iCellX;          // 04
    std::int32_t iCellY;          // 08
    std::int32_t iDetachTime;     // 0C
};
