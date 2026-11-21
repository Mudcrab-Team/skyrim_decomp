// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysEmitterLifeSpanCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysEmitterLifeSpanCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterLifeSpanCtlr();
    ~NiPSysEmitterLifeSpanCtlr() override = default;
};
static_assert(sizeof(NiPSysEmitterLifeSpanCtlr) == 0x60, "observed allocation size");
