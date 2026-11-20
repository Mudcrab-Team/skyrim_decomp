// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysInitialRotSpeedVarCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysInitialRotSpeedVarCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysInitialRotSpeedVarCtlr();
    ~NiPSysInitialRotSpeedVarCtlr() override = default;
};
static_assert(sizeof(NiPSysInitialRotSpeedVarCtlr) == 0x60, "observed allocation size");
