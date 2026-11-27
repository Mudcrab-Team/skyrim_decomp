// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// Adapted bodies: AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// SPDX-License-Identifier: CC0-1.0
// BSFrustumFOVController, NiFloatInterpController, NiObject, NiCloningProcess, AutoMemContext, CreateClone: CRASHLOGGER_PDB(59818@2026.10.24)
// CopyMembers, g_memoryContext_tls_0x768: GUESS(low)
// 0xf8d4e0 BSFrustumFOVController::CreateClone
#include "BSFrustumFOVController_f8d4e0.h"

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

inline BSFrustumFOVController::BSFrustumFOVController() : NiFloatInterpController()
{
}

// Clones this frustum FOV controller under its memory allocation context.
NiObject* BSFrustumFOVController::CreateClone(NiCloningProcess& cloning)
{
    AutoMemContext context(0x3F);
    BSFrustumFOVController* clone = new BSFrustumFOVController();
    CopyMembers(clone, cloning);
    return clone;
}
