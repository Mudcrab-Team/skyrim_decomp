// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// NiPSysFieldMaxDistanceCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysFieldMaxDistanceCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysFieldMaxDistanceCtlr();
    ~NiPSysFieldMaxDistanceCtlr() override = default;
};
static_assert(sizeof(NiPSysFieldMaxDistanceCtlr) == 0x60, "observed allocation size");
