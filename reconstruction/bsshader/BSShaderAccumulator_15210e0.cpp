// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x15210e0 BSShaderAccumulator::ClearSunOcclusionTests
#include "BSShaderAccumulator_15210e0.h"

void BSShaderAccumulator::ClearSunOcclusionTests()
{
    for (unsigned int i = 0; i < 3; ++i) {
        auto& test = sunOcclusionTests[i];
        if (test.occlusionQuery) {
            queryRenderer.ReleaseQuery(test.occlusionQuery);
            test.occlusionQuery = nullptr;
            test.waiting = false;
        }
    }
    waitingForSunQuery = false;
}
