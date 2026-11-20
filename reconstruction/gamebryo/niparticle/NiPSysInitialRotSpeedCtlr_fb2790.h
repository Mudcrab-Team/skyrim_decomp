// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysInitialRotSpeedCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysInitialRotSpeedCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysInitialRotSpeedCtlr();
    ~NiPSysInitialRotSpeedCtlr() override = default;
};
static_assert(sizeof(NiPSysInitialRotSpeedCtlr) == 0x60, "observed allocation size");
