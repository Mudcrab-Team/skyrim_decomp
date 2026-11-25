// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSShaderAccumulator::RenderFirstPersonView_End, BSBatchRenderer and BSShaderAccumulator layouts, ResetQueuedPassCounts: CRASHLOGGER_PDB(59818@2026.10.24)
// PassIndexNode, Recycle, PassNodePool and ClearPassIndexList: GUESS(low) STANDIN
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
    void RenderFirstPersonView_End(bool clear);
};
