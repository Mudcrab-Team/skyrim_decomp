// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, SortAlphaGeometryGroups, GeometryGroup, PersistentPassList, BSRenderPass, batchRenderer, passList, head, tail, UnkPtr4, depth, count, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// alphaGroupCount, sortedAlphaGroups, CompareAlphaGroups: GUESS(low)
#pragma once

struct BSRenderPass;
struct PersistentPassList
{
    BSRenderPass* head;
    BSRenderPass* tail;
};

class BSBatchRenderer
{
public:
    struct GeometryGroup;
    static void SortAlphaGeometryGroups();

    static unsigned int alphaGroupCount;
    static GeometryGroup sortedAlphaGroups[];
    static int CompareAlphaGroups(const void* first, const void* second);
};

struct BSBatchRenderer::GeometryGroup
{
    BSBatchRenderer* batchRenderer;
    PersistentPassList passList;
    unsigned long long UnkPtr4;
    float depth;
    unsigned short count;
    unsigned char flags;
};
static_assert(sizeof(BSBatchRenderer::GeometryGroup) == 0x28, "alpha sort element size");
