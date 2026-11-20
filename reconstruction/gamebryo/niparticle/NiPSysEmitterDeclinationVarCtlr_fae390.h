// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysEmitterDeclinationVarCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysEmitterDeclinationVarCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterDeclinationVarCtlr();
    ~NiPSysEmitterDeclinationVarCtlr() override = default;
};
static_assert(sizeof(NiPSysEmitterDeclinationVarCtlr) == 0x60, "observed allocation size");
