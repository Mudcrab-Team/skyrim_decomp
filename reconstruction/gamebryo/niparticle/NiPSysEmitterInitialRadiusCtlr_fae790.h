// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysEmitterInitialRadiusCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysEmitterInitialRadiusCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterInitialRadiusCtlr();
    ~NiPSysEmitterInitialRadiusCtlr() override = default;
};
static_assert(sizeof(NiPSysEmitterInitialRadiusCtlr) == 0x60, "observed allocation size");
