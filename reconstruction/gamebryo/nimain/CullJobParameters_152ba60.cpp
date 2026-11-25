// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x152ba60 CullJob_AccumulateAndFlush
// CI hash: 0x152ba60 ?CullJob_AccumulateAndFlush@@YAXIPEBUCullJobParameters@@@Z
#include "CullJobParameters_152ba60.h"

void CullJob_AccumulateAndFlush(unsigned int phase, const CullJobParameters* job)
{
    BSCullingProcess* process = BSCullingProcess::TakePendingCullingProcess();
    if (phase == 0) {
        process->AccumulateGeometry(job->accumulator);
        process->ClearCollectedGeometry();
    } else if (phase == 1) {
        process->FlushAlphaGroupQueue();
    }
    if (job->accumulator)
        process->portalGraphEntry = nullptr;
}
