// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xfeea10 BSCullingProcess::TestBaseVisibility2
#include "BSCullingProcess_feea10.h"

bool BSCullingProcess::TestBaseVisibility2(BSOcclusionPlane& plane)
{
    return plane.TestPlanes(planes, camera->worldPosition);
}
