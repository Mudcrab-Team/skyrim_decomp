// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// SPDX-License-Identifier: CC0-1.0
// NiAlphaAccumulator, NiBackToFrontAccumulator, NiObject, NiCloningProcess, AutoMemContext, CreateClone, observeNoSortHint, sortByClosestPoint, interfaceSort: CRASHLOGGER_PDB(59818@2026.10.24)
// CopyMembers, g_memoryContext_tls_0x768: GUESS(low)
// 0xf0f120 NiAlphaAccumulator::CreateClone
#include "NiAlphaAccumulator_f0f120.h"

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

inline NiAlphaAccumulator::NiAlphaAccumulator() :
    observeNoSortHint(true), sortByClosestPoint(false), interfaceSort(false)
{
}

inline void NiAlphaAccumulator::CopyMembers(NiAlphaAccumulator* dest, NiCloningProcess& cloning)
{
    NiBackToFrontAccumulator::CopyMembers(dest, cloning);
    dest->observeNoSortHint = observeNoSortHint;
    dest->sortByClosestPoint = sortByClosestPoint;
}

NiObject* NiAlphaAccumulator::CreateClone(NiCloningProcess& cloning)
{
    AutoMemContext context(0x3D);
    NiAlphaAccumulator* clone = new NiAlphaAccumulator();
    CopyMembers(clone, cloning);
    return clone;
}
