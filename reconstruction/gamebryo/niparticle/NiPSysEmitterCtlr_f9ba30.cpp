// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// 0xf9ba30 NiPSysEmitterCtlr::ProcessClone
// Adapted bodies: NiPSysEmitterCtlr::ProcessClone follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp:17
// Adapted bodies: NiPSysEmitterCtlr::ProcessClone follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp:72
#include "NiPSysEmitterCtlr_f9ba30.h"

void NiPSysEmitterCtlr::ProcessClone(NiCloningProcess& process)
{
    NiPSysModifierCtlr::ProcessClone(process);
    NiInterpolator* interpolator = m_spVisibilityInterpolator;
    if (interpolator)
        interpolator->ProcessClone(process);
}
