// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: CollapseAllInterps.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niblendinterpolator.cpp:548
// 0xf5c6b0 CollapseAllInterps
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/niblendinterpolator.cpp:577
#include "NiBlendInterpolator_f5c6b0.h"

void CollapseAllInterps(BlendInterpS* self, int)
{
    if (self->m_ucInterpCount == 1)
    {
        self->m_pSingleInterpolator->Collapse2();
        return;
    }
    for (unsigned char uc = 0; uc < self->m_ucArraySize; uc++)
    {
        ItemS* kItem = &self->m_pInterpArray[uc];
        if (kItem->m_spControllerInterpolator)
            kItem->m_spControllerInterpolator->Collapse2();
    }
}
