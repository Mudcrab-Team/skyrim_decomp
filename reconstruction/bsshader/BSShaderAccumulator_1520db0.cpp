// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: BSSpinLock::Unlock follows the project unit BSShaderAccumulator_151e430.cpp; AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderAccumulator, BSBatchRenderer, BSShader, BSShaderProperty, BSRenderPass, BSGeometry, AutoMemContext, BSSpinLock, NiCamera, IssueSunOcclusionQuery, MakeRenderPass, SetupAndDrawPass, ClearRenderPass, ClearBSShaders, BSGraphics::GetThreadRenderContextLock, SetCameraData, waitingForSunQuery, sunOcclusionTests, occlusionQuery, percentOccluded, frameCount, waiting, shaderProperty: CRASHLOGGER_PDB(59818@2026.10.24)
// Unlock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// owningThread, lockCount, RenderLockGuard, g_memoryContext_tls_0x768, g_renderer, g_renderState, g_skyShader, CreateOcclusionQuery, BeginOcclusionQuery, EndOcclusionQuery: GUESS(low)
// 0x1520db0 BSShaderAccumulator::IssueSunOcclusionQuery
#include "BSShaderAccumulator_1520db0.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

class AutoMemContext
{
public:
    explicit AutoMemContext(unsigned int context) : previous(g_memoryContext_tls_0x768)
    {
        g_memoryContext_tls_0x768 = context;
    }

    ~AutoMemContext()
    {
        g_memoryContext_tls_0x768 = previous;
    }

private:
    unsigned int previous;
};

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

void BSShaderAccumulator::IssueSunOcclusionQuery(BSGeometry* geometry, unsigned int index, NiCamera* cam)
{
    AutoMemContext context(0x5D);
    if (waitingForSunQuery || index >= 3) {
        return;
    }
    if (sunOcclusionTests[index].waiting) {
        return;
    }
    void* query = sunOcclusionTests[index].occlusionQuery;
    if (!query) {
        query = CreateOcclusionQuery(&g_renderer);
        sunOcclusionTests[index].occlusionQuery = query;
        if (!query) {
            sunOcclusionTests[index].waiting = false;
            sunOcclusionTests[index].percentOccluded = 0.0f;
            sunOcclusionTests[index].frameCount = 0;
            return;
        }
    }

    BeginOcclusionQuery(&g_renderer, query);
    g_renderState.SetCameraData(cam, 0);
    BSShaderProperty* prop = geometry->shaderProperty;
    RenderLockGuard guard(BSGraphics::GetThreadRenderContextLock());
    BSRenderPass* pass = g_skyShader->MakeRenderPass(prop, geometry, 2, 0, nullptr);
    BSBatchRenderer::SetupAndDrawPass(pass, 2, false, 0);
    BSRenderPass::ClearRenderPass(pass);
    ClearBSShaders(false);
    EndOcclusionQuery(&g_renderer, query);
    sunOcclusionTests[index].waiting = true;
    sunOcclusionTests[index].frameCount = 0;
}
