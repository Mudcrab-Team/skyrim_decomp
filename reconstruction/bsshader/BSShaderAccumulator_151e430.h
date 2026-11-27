// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: BSSpinLock::Unlock follows the project unit ShadowSceneNode.cpp.
// BSShaderAccumulator, AccumulateSceneGraph, AccumulateSceneGraphContext, accumulator, filterByShaderProperty, BSGraphics::GetThreadRenderContextLock, AccumulateSceneGraphNode: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderLockGuard: GUESS(low); stand-in for the guard that releases the render context lock
#pragma once

#include <intrin.h>

struct BSSpinLock
{
    unsigned long owningThread;
    long lockCount;
    void Unlock();
};
namespace BSGraphics {
    BSSpinLock* GetThreadRenderContextLock();
}

class RenderLockGuard
{
public:
    explicit RenderLockGuard(BSSpinLock*) noexcept;
    ~RenderLockGuard();
private:
    BSSpinLock* lock;
};
class NiAVObject;
class BSShaderAccumulator
{
public:
    void AccumulateSceneGraph(NiAVObject* root, bool filter);
};
struct AccumulateSceneGraphContext
{
    BSShaderAccumulator* accumulator;
    bool filterByShaderProperty;
};
unsigned AccumulateSceneGraphNode(NiAVObject*, AccumulateSceneGraphContext*);
