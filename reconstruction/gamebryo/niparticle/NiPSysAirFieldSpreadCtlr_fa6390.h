// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysAirFieldSpreadCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysAirFieldSpreadCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysAirFieldSpreadCtlr();
    ~NiPSysAirFieldSpreadCtlr() override = default;
};
static_assert(sizeof(NiPSysAirFieldSpreadCtlr) == 0x60, "observed allocation size");
