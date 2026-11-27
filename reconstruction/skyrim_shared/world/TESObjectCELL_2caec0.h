// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// TESObjectCELL, TESWorldSpace, LOADED_CELL_DATA, BSPortalGraph, cellFlags, worldSpace, loadedData, portalGraph: CRASHLOGGER_PDB(59818@2026.10.24)
// GetPortalGraph, unknown000, unknown042: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BSPortalGraph;

class TESWorldSpace
{
public:
    BSPortalGraph* GetPortalGraph() const;
};

struct LOADED_CELL_DATA
{
    BSPortalGraph* portalGraph;  // 00
};

class TESObjectCELL
{
public:
    BSPortalGraph* GetPortalGraph() const;

    std::uint8_t      unknown000[0x40];   // 000
    std::uint16_t     cellFlags;          // 040
    std::uint8_t      unknown042[0xE6];   // 042
    TESWorldSpace*    worldSpace;         // 128
    LOADED_CELL_DATA* loadedData;         // 130
};
static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(TESObjectCELL, worldSpace) == 0x128, "worldSpace offset");
static_assert(offsetof(TESObjectCELL, loadedData) == 0x130, "loadedData offset");
