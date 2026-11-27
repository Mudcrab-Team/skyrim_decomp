// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: BSSpinLock::Unlock follows the project unit ShadowSceneNode.cpp.
// BSShaderAccumulator, AccumulateSceneGraph, AccumulateSceneGraphContext, accumulator, filterByShaderProperty, BSGraphics::GetThreadRenderContextLock, AccumulateSceneGraphNode: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderLockGuard: GUESS(low); stand-in for the guard that releases the render context lock
// 0x151e430 BSShaderAccumulator::AccumulateSceneGraph
// CI hash: 0x151e430 ?AccumulateSceneGraph@BSShaderAccumulator@@QEAAXPEAVNiAVObject@@_N@Z
#include "BSShaderAccumulator_151e430.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

inline void BSSpinLock::Unlock()
{
    // Observe the owner after prior protected loads complete.
    _mm_lfence();
    if (owningThread == GetCurrentThreadId()) {
        if (lockCount == 1) {
            owningThread = 0;
            // Publish the owner change before making the lock available.
            _mm_mfence();
            // Only the owner removes the last recursive acquisition.
            _InterlockedCompareExchange(&lockCount, 0, 1);
        } else {
            // The recursive count is shared across threads.
            _InterlockedDecrement(&lockCount);
        }
    }
}

inline RenderLockGuard::~RenderLockGuard()
{
    if (lock) {
        lock->Unlock();
    }
}

void BSShaderAccumulator::AccumulateSceneGraph(NiAVObject* root, bool filter)
{
    RenderLockGuard guard(BSGraphics::GetThreadRenderContextLock());
    AccumulateSceneGraphContext context{this, filter};
    AccumulateSceneGraphNode(root, &context);
}
