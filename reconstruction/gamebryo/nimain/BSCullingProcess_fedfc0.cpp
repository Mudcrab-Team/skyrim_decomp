// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfedfc0 BSCullingProcess::AppendVirtual
#include "BSCullingProcess_fedfc0.h"

void BSCullingProcess::AppendVirtual(BSGeometry* geometry, unsigned int argument)
{
    if (!isGroupingAlphas && argument == static_cast<unsigned int>(-1)) {
        methods->AppendNonAccum(this, geometry, alphaGroupStopIndex);
        return;
    }
    CullEntry* entry = freeEntries.PopFreeQueueEntry();
    entry->geometry = geometry;
    entry->argument = argument;
    entry->group = alphaGroupStopIndex;
    pending.PushQueueEntry(entry);
}
