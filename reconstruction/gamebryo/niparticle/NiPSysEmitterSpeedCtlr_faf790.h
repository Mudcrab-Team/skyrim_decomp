// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysEmitterSpeedCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysEmitterSpeedCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterSpeedCtlr();
    ~NiPSysEmitterSpeedCtlr() override = default;
};
static_assert(sizeof(NiPSysEmitterSpeedCtlr) == 0x60, "observed allocation size");
