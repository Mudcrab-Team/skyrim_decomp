// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysInitialRotAngleCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysInitialRotAngleCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysInitialRotAngleCtlr();
    ~NiPSysInitialRotAngleCtlr() override = default;
};
static_assert(sizeof(NiPSysInitialRotAngleCtlr) == 0x60, "observed allocation size");
