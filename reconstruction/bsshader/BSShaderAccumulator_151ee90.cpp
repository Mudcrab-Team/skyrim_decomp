// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x151ee90 BSShaderAccumulator::FinishAccumulatingDispatch
#include "BSShaderAccumulator_151ee90.h"

void BSShaderAccumulator::FinishAccumulatingDispatch(int flags)
{
    BSShaderManager::SetRenderMode(renderMode);
    if (renderMode == 0) {
        FinishAccumulatingCommonPasses(flags);
    } else if (finishPasses[renderMode]) {
        finishPasses[renderMode](this, flags);
    } else {
        finishPasses[0](this, flags);
    }
}
