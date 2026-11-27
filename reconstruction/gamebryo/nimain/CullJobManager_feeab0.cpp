// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfeeab0 SetupCullingJobManager2
// CI hash: 0xfeeab0 ?SetupCullingJobManager2@@YAPEAUCullJobManager@@PEAU1@@Z
#include "CullJobManager_feeab0.h"

CullJobManager* SetupCullingJobManager2(CullJobManager* manager)
{
    manager->Initialize(&jobStorage, 0, 128, 128, 1, workerCount, false, nullptr, false);
    return manager;
}
