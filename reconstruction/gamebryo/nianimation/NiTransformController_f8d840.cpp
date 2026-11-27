// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiTransformController::IsTargetOfType.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niviscontroller.cpp:106
// 0xf8d840 NiTransformController::IsTargetOfType
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/niviscontroller.cpp:92
#include "NiTransformController_f8d840.h"

bool NiTransformController::IsTargetOfType(NiObjectNET* pkTarget) const
{
    if (pkTarget)
    {
        NiRTTI* pkRTTI = pkTarget->GetRTTI();
        if (pkRTTI)
        {
            do
            {
                if (pkRTTI == &g_011f4428_arg1)
                    return true;
                pkRTTI = pkRTTI->m_pkBase;
            } while (pkRTTI);
        }
    }
    return false;
}
