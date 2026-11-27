// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GeometryGroup, geometryGroups, alphaGroup, batchRenderer, BSRenderPass, NiCamera: CRASHLOGGER_PDB(59818@2026.10.24)
// SortGroupPasses, SortPasses, currentRendererGroup, AppendPassToAlphaGroup, AppendPass, ClearRecycledPassNodes: GUESS(low)
// PassIndexNode, PassNodePool, passNodePool, Clear, Recycle: GUESS(low)
#pragma once

class NiCamera;
struct BSRenderPass;
class BSBatchRenderer
{
public:
    struct GeometryGroup
    {
        BSBatchRenderer* batchRenderer;
        void AppendPass(BSRenderPass* pass, unsigned char flags);
    };

    void SortGroupPasses(NiCamera* camera, unsigned int group);
    void AppendPassToAlphaGroup(BSRenderPass* pass, GeometryGroup* group);
    static void ClearRecycledPassNodes();

private:
    enum { currentRendererGroup = 17 };
    void SortPasses(NiCamera* camera);
    unsigned char unknown00[0x70];
    GeometryGroup* geometryGroups[16];
    GeometryGroup* alphaGroup;
};

struct PassIndexNode
{
    using Recycle = void (*)(PassIndexNode*, void*);
    unsigned int pass;
    PassIndexNode* next;
    void Clear(Recycle recycle, void* context);
    ~PassIndexNode()
    {
        Clear(nullptr, nullptr);
    }
};

struct PassNodePool
{
    PassIndexNode* head;
};
extern PassNodePool passNodePool;
