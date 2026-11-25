// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x151ed40 BSShaderAccumulator::FinishAccumulatingAppendLitPassesGroupsOnly
#include "BSShaderAccumulator_151ed40.h"

bool BSShaderAccumulator::FinishAccumulatingAppendLitPassesGroupsOnly(BSGeometry* geometry, BSShaderProperty* property)
{
    auto list = property->methods->GetLitPasses(property, geometry, renderMode, this);
    if (list) {
        for (auto pass = *list; pass; pass = pass->next) {
            if (pass->passEnum) {
                switch (pass->accumulationHint) {
                case 6:
                    batchRenderer->AppendPassToGeometryGroup(pass, 0, false);
                    break;
                case 7:
                    batchRenderer->AppendPassToGeometryGroup(pass, 1, false);
                    break;
                }
            }
        }
    }
    return true;
}
