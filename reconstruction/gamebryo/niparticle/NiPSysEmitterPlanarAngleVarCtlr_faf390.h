// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysEmitterPlanarAngleVarCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysEmitterPlanarAngleVarCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterPlanarAngleVarCtlr();
    ~NiPSysEmitterPlanarAngleVarCtlr() override = default;
};
static_assert(sizeof(NiPSysEmitterPlanarAngleVarCtlr) == 0x60, "observed allocation size");
