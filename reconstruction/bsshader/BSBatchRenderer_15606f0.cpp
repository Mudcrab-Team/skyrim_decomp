// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, SortAlphaGeometryGroups, GeometryGroup, PersistentPassList, BSRenderPass, batchRenderer, passList, head, tail, UnkPtr4, depth, count, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// alphaGroupCount, sortedAlphaGroups, CompareAlphaGroups: GUESS(low)
// 0x15606f0 BSBatchRenderer::SortAlphaGeometryGroups
#include "BSBatchRenderer_15606f0.h"

#include <cstddef>

extern "C" __declspec(dllimport) void __cdecl qsort(
    void* base, std::size_t count, std::size_t width,
    int (__cdecl* compare)(const void*, const void*));

// Sort the populated prefix of the shared alpha-group array.
void BSBatchRenderer::SortAlphaGeometryGroups()
{
    qsort(sortedAlphaGroups, alphaGroupCount, sizeof(GeometryGroup), CompareAlphaGroups);
}
