// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports MemoryContextScope::~MemoryContextScope as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00c80000_o2.cpp:6643
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00c80000_o2.cpp:5505
// 0x2bccc0 TESObjectCELL::SetLand
#include "TESObjectCELL_2bccc0.h"

namespace
{
    struct MemoryContextScope
    {
        explicit MemoryContextScope(std::uint32_t nextContext)
            : previousContext(gMemoryContext_tls_0x768)
        {
            gMemoryContext_tls_0x768 = nextContext;
        }

        ~MemoryContextScope()
        {
            gMemoryContext_tls_0x768 = previousContext;
        }

        std::uint32_t previousContext;
    };
}

// Replace an exterior cell's landscape object while switching the thread memory context.
void TESObjectCELL::SetLand(TESObjectLAND* land)
{
    if ((cellFlags & 1) == 0 && cellLand != land) {
        MemoryContextScope scope(0x6C);
        delete cellLand;
        cellLand = land;
    }
}
