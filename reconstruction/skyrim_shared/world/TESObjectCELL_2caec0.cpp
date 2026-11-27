// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x2caec0 TESObjectCELL::GetPortalGraph
// Adapted bodies: none
#include "TESObjectCELL_2caec0.h"

// Return the portal graph from this cell's loaded data, falling back to its exterior worldspace.
BSPortalGraph* TESObjectCELL::GetPortalGraph() const
{
    if (loadedData && loadedData->portalGraph) {
        return loadedData->portalGraph;
    }
    if ((cellFlags & 1) == 0 && worldSpace) {
        return worldSpace->GetPortalGraph();
    }
    return nullptr;
}
