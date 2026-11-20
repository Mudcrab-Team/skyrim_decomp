// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysModifierActiveCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysModifierActiveCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysModifierActiveCtlr();
    ~NiPSysModifierActiveCtlr() override = default;
};
static_assert(sizeof(NiPSysModifierActiveCtlr) == 0x60, "observed allocation size");
