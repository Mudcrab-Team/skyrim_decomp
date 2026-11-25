// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfeea70 BSCullingProcess::TakePendingCullingProcess
#include "BSCullingProcess_feea70.h"

BSCullingProcess* BSCullingProcess::TakePendingCullingProcess()
{
    pendingJobs.Finish();
    pendingJobs.CallClear();
    BSCullingProcess* process = pendingProcess;
    pendingProcess = nullptr;
    return process;
}
