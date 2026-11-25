// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x151edd0 BSShaderAccumulator::FinishAccumulatingAppendOcclusionPasses
#include "BSShaderAccumulator_151edd0.h"

bool BSShaderAccumulator::FinishAccumulatingAppendOcclusionPasses(BSGeometry* geometry, BSShaderProperty* property)
{
    auto list = property->methods->GetOcclusionPasses(property, geometry, renderMode, this);
    if (list) {
        for (auto pass = *list; pass; pass = pass->next) {
            batchRenderer->AppendPassToGeometryGroup(pass, 14, false);
        }
    }
    return true;
}
