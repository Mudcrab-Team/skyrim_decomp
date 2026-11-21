// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysAirFieldInheritVelocityCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysAirFieldInheritVelocityCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysAirFieldInheritVelocityCtlr();
    ~NiPSysAirFieldInheritVelocityCtlr() override = default;
};
static_assert(sizeof(NiPSysAirFieldInheritVelocityCtlr) == 0x60, "observed allocation size");
