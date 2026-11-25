// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xfeea50 BSCullingProcess::TestBaseVisibility
#include "BSCullingProcess_feea50.h"

bool BSCullingProcess::TestBaseVisibility(BSMultiBoundShape& shape)
{
    return shape.methods->TestPlanes(&shape, planes);
}
