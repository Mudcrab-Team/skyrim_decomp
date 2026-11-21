// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysFieldMagnitudeCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysFieldMagnitudeCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysFieldMagnitudeCtlr();
    ~NiPSysFieldMagnitudeCtlr() override = default;
};
static_assert(sizeof(NiPSysFieldMagnitudeCtlr) == 0x60, "observed allocation size");
