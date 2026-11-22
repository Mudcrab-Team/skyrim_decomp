// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the bodies are written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0xf9aad0 NiPSysEmitterCtlr::Stop
// 0xf9a8d0 NiPSysEmitterCtlr::SaveBinary
// 0xf9b800 NiPSysEmitterCtlr::GetInterpolator
// 0xfa0950 NiPSysEmitterCtlr::Functionfa0950
// 0xff4f40 NiPSysEmitterCtlr::Functionff4f40
// Adapted bodies: none
#include "NiPSysEmitterCtlr.h"

void* NiPSysEmitterCtlr::GetInterpolator(std::uint16_t a_index) const
{
    if (a_index == 0)
        return interpolator0;
    if (a_index == 1)
        return interpolator1;
    return nullptr;
}

void NiPSysEmitterCtlr::Functionfa0950(NiPSysEmitterCtlr* a_other)
{
    Functionf62de0(this, a_other);
    Functioneb11e0(a_other->field50, this->field50);
}

void NiPSysEmitterCtlr::SaveBinary(NiStream* a_stream)
{
    Functionfa0a00(this, a_stream);
    a_stream->WritePointer(interpolator1);
}

void NiPSysEmitterCtlr::Stop()
{
    field74 = 0;
    field70 = 0xFF7FFFFFu;
    Functionef7340(this);
}

void NiPSysEmitterCtlr::Functionff4f40(NiPSysEmitterCtlr* a_other)
{
    Functionf9a3f0(this, a_other);
    a_other->field98 = field98;
}

std::uint32_t NiPSysEmitterCtlr::GetInterpolatorCount() const
{
    return 0x2;
}
