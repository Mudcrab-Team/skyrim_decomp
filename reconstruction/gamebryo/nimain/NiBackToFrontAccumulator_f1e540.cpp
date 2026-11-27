// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// SPDX-License-Identifier: CC0-1.0
// NiBackToFrontAccumulator, NiAccumulator, NiObject, NiCloningProcess, AutoMemContext, CreateClone, itemsList, numItems, maxItems, items, depths, currItem: CRASHLOGGER_PDB(59818@2026.10.24)
// CopyMembers, g_memoryContext_tls_0x768: GUESS(low)
// 0xf1e540 NiBackToFrontAccumulator::CreateClone
#include "NiBackToFrontAccumulator_f1e540.h"

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

inline NiBackToFrontAccumulator::NiBackToFrontAccumulator() :
    itemsList{}, numItems(0), maxItems(0), items(nullptr), depths(nullptr), currItem(0)
{
}

NiObject* NiBackToFrontAccumulator::CreateClone(NiCloningProcess& cloning)
{
    AutoMemContext context(0x3D);
    NiBackToFrontAccumulator* clone = new NiBackToFrontAccumulator();
    NiAccumulator::CopyMembers(clone, cloning);
    return clone;
}
