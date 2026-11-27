// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x15212d0 BSShaderAccumulator::RenderFirstPersonView_End
#include "BSShaderAccumulator_15212d0.h"

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

void BSShaderAccumulator::RenderFirstPersonView_End(bool clear)
{
    if (clear || batchRenderer->autoClearPasses)
        batchRenderer->activePassIndexList.Clear();
    batchRenderer->ResetQueuedPassCounts();
}
