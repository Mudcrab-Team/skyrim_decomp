// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// Adapted bodies: AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// SPDX-License-Identifier: CC0-1.0
// NiCamera, NiAVObject, NiObject, NiCloningProcess, AutoMemContext, CreateClone, CopyMembers, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust: CRASHLOGGER_PDB(59818@2026.10.24)
// worldTranslate, g_memoryContext_tls_0x768: GUESS(low)
// 0xeeeed0 NiCamera::CreateClone
#include "NiCamera_eeeed0.h"

#include <cstring>

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

inline void NiCamera::CopyMembers(NiCamera* destination, NiCloningProcess& cloning)
{
    NiAVObject::CopyMembers(destination, cloning);
    std::memcpy(destination->worldToCam, worldToCam, sizeof(worldToCam));
    destination->worldTranslate.x = worldTranslate.x;
    destination->worldTranslate.y = worldTranslate.y;
    destination->worldTranslate.z = worldTranslate.z;
    destination->viewFrustum = viewFrustum;
    destination->port = port;
    destination->lodAdjust = lodAdjust;
    destination->minNearPlaneDist = minNearPlaneDist;
    destination->maxFarNearRatio = maxFarNearRatio;
}

// Clones this camera under its memory allocation context.
NiObject* NiCamera::CreateClone(NiCloningProcess& cloning)
{
    AutoMemContext context(0x3D);
    NiCamera* clone = new NiCamera();
    CopyMembers(clone, cloning);
    return clone;
}
