// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x153a5b0 Main::PostRenderCleanup
#include "Main_153a5b0.h"

// Run post-render cleanup callbacks and advance the frame warmup counter.
void Main::PostRenderCleanup()
{
    if (gRenderCleanupTarget != nullptr) {
        gRenderCleanupTarget->Cleanup();
    }
    gPostRenderWorker->Run();
    if (gPostRenderFlag) {
        ResetRenderState();
    }
    NotifyRenderDone(0);
    if (!gPostRenderReady) {
        if (++gPostRenderCount > 20) {
            gPostRenderReady = true;
            gPostRenderNotify = true;
            gPostRenderCount = 0;
        }
    }
}
