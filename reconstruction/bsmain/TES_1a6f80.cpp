// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the interior and loaded-grid query selection.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1a6f80 TES::ResolveCellQueryNode
// 0x1a6fd0 TES::ResolveQueryNode
#include "TES_1a6f80.h"
#include "skyrim_shared/world/TESObjectCELL_2c85c0.h"

// g_loadedGridLength: GUESS(low)
extern std::uint32_t g_loadedGridLength;

NiAVObject* TES::ResolveCellQueryNode(const CellSurfaceQuery& query)
{
    auto* cell = interiorCell;
    if (!cell) {
        const auto center = g_loadedGridLength / 2;
        cell = *gridCells->GetCellSlot(center, center);
    }
    if (cell) {
        return cell->ResolveQueryNode(query);
    }
    return nullptr;
}

NiAVObject* TES::ResolveQueryNode(const CellSurfaceQuery& query, bool useCell)
{
    if (useCell) {
        return ResolveCellQueryNode(query);
    }
    return QueryWorldNode(query);
}
