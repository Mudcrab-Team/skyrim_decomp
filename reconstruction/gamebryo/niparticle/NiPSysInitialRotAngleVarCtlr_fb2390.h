// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysInitialRotAngleVarCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysInitialRotAngleVarCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysInitialRotAngleVarCtlr();
    ~NiPSysInitialRotAngleVarCtlr() override = default;
};
static_assert(sizeof(NiPSysInitialRotAngleVarCtlr) == 0x60, "observed allocation size");
