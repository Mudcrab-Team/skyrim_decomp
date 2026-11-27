// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: PassIndexNode::Clear and the list declarations follow the project unit BSShaderAccumulator_15212d0.
// BSShaderAccumulator, RenderFirstPersonView_Begin, autoClearPasses, activePassIndexList, RenderBatches, BSBatchRenderer, batchRenderer, ResetQueuedPassCounts: CRASHLOGGER_PDB(59818@2026.10.24)
// PassIndexNode, PassNodePool, Recycle: GUESS(low)
#pragma once

struct PassNodePool;
struct PassIndexNode {
    unsigned int pass;
    PassIndexNode* next;
    void Recycle(PassNodePool* pool);
    void Clear();
};
extern PassNodePool passNodePool;
struct BSBatchRenderer {
    unsigned char unknown00[0x58];
    PassIndexNode activePassIndexList;
    unsigned int groupingAlphasCount;
    bool autoClearPasses;
    void ResetQueuedPassCounts();
};
struct NiCamera;
struct BSShaderAccumulator {
    unsigned char unknown00[0x10];
    NiCamera* camera;
    unsigned char unknown18[0x118];
    BSBatchRenderer* batchRenderer;
    void RenderBatches(unsigned first, unsigned last, unsigned flags, int group);
    void RenderFirstPersonView_Begin();
};
