// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x1520610 BSShaderAccumulator::FinishAccumulatingMode24
#include "BSShaderAccumulator_1520610.h"

inline void BSBatchRenderer::ClearPassIndexList()
{
    PassIndexNode* node = activePassIndexList.next;
    while (node) {
        PassIndexNode* next = node->next;
        node->next = nullptr;
        activePassIndexList.next->Recycle(&passNodePool);
        activePassIndexList.next = next;
        node = next;
    }
    activePassIndexList.pass = 0;
}

void BSShaderAccumulator::FinishAccumulatingMode24()
{
    if (camera) {
        BSBatchRenderer* renderer = batchRenderer;
        if (renderer->autoClearPasses)
            renderer->ClearPassIndexList();
        batchRenderer->ResetQueuedPassCounts();
    }
}
