// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysAirFieldAirFrictionCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysAirFieldAirFrictionCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysAirFieldAirFrictionCtlr();
    ~NiPSysAirFieldAirFrictionCtlr() override = default;
};
static_assert(sizeof(NiPSysAirFieldAirFrictionCtlr) == 0x60, "observed allocation size");
