// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xfeea30 BSCullingProcess::TestBaseVisibility1
#include "BSCullingProcess_feea30.h"

bool BSCullingProcess::TestBaseVisibility1(BSMultiBound& bound)
{
    return bound.data->methods->TestPlanes(bound.data, planes);
}
