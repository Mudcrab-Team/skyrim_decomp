// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiBoolInterpController::SynchronizePoseInterpolator.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00ac0000_o2.cpp:1693
// 0xf98840 NiBoolInterpController::SynchronizePoseInterpolator
// Adapted helpers: IsKindOfType
#include "NiBoolInterpController_f98840.h"

void NiBoolInterpController::SynchronizePoseInterpolator(PObjAD24* pkInterp, unsigned short usIndex)
{
    bool bValue;
    PObjAD24* pkBoolInterp;
    if (pkInterp == 0)
        pkBoolInterp = 0;
    else
        pkBoolInterp = pkInterp->IsKindOfType((const void*)&g_012007a0) ? pkInterp : 0;
    this->slotF0(&bValue);
    pkBoolInterp->Func008cd050(bValue);
}
