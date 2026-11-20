// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysEmitterDeclinationCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysEmitterDeclinationCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterDeclinationCtlr();
    ~NiPSysEmitterDeclinationCtlr() override = default;
};
static_assert(sizeof(NiPSysEmitterDeclinationCtlr) == 0x60, "observed allocation size");
