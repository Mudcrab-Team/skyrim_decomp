// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the bodies are written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0xfa0950 NiPSysEmitterCtlr::Functionfa0950
// 0xff4f40 NiPSysEmitterCtlr::Functionff4f40
// Adapted bodies: none
#include "NiPSysEmitterCtlr_fa0950.h"

void NiPSysEmitterCtlr::Functionfa0950(NiPSysEmitterCtlr* a_other)
{
    Functionf62de0(this, a_other);
    Functioneb11e0(a_other->field50, this->field50);
}

void NiPSysEmitterCtlr::Functionff4f40(NiPSysEmitterCtlr* a_other)
{
    Functionf9a3f0(this, a_other);
    a_other->field98 = field98;
}
