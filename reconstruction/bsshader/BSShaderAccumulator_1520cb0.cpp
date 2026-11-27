// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: PassIndexNode::Clear and the list declarations follow the project unit BSShaderAccumulator_15212d0.
// BSShaderAccumulator, RenderFirstPersonView_Begin, autoClearPasses, activePassIndexList, RenderBatches, BSBatchRenderer, batchRenderer, ResetQueuedPassCounts: CRASHLOGGER_PDB(59818@2026.10.24)
// PassIndexNode, PassNodePool, Recycle: GUESS(low)
// 0x1520cb0 BSShaderAccumulator::RenderFirstPersonView_Begin
// CI hash: 0x1520cb0 ?RenderFirstPersonView_Begin@BSShaderAccumulator@@QEAAXXZ
#include "BSShaderAccumulator_1520cb0.h"

inline void PassIndexNode::Clear()
{
    PassIndexNode* node = next;
    while (node) {
        PassIndexNode* following = node->next;
        node->next = nullptr;
        next->Recycle(&passNodePool);
        next = following;
        node = following;
    }
    pass = 0;
}


void BSShaderAccumulator::RenderFirstPersonView_Begin()
{
    const unsigned firstPass = 0x5c006073;
    RenderBatches(firstPass, firstPass + 1, 0, -1);
    if (batchRenderer->autoClearPasses) {
        batchRenderer->activePassIndexList.Clear();
    }
    batchRenderer->ResetQueuedPassCounts();
}
