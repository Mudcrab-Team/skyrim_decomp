// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysFieldAttenuationCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysFieldAttenuationCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysFieldAttenuationCtlr();
    ~NiPSysFieldAttenuationCtlr() override = default;
};
static_assert(sizeof(NiPSysFieldAttenuationCtlr) == 0x60, "observed allocation size");
