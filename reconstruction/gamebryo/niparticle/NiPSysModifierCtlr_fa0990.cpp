// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// 0xfa0990 NiPSysModifierCtlr::LoadBinary
// Adapted bodies: NiPSysModifierCtlr::LoadBinary follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niextradatacontroller.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niextradatacontroller.cpp:6
// Adapted bodies: NiPSysModifierCtlr::LoadBinary follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nianimation/niextradatacontroller.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nianimation/niextradatacontroller.cpp:19
#include "NiPSysModifierCtlr_fa0990.h"

void NiPSysModifierCtlr::LoadBinary(NiStream& stream)
{
    NiSingleInterpController::LoadBinary(stream);
    if (stream.nifMaxVersion < 0x14010001)
        stream.LoadFixedStringLegacy(m_kTargetModifierName);
    else
        stream.LoadFixedString(m_kTargetModifierName);
}
