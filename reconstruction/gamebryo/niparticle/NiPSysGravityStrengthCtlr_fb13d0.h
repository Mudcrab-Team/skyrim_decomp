// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysGravityStrengthCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysGravityStrengthCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysGravityStrengthCtlr();
    ~NiPSysGravityStrengthCtlr() override = default;
};
static_assert(sizeof(NiPSysGravityStrengthCtlr) == 0x60, "observed allocation size");
