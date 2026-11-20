// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the observed cleanup calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysVolumeEmitter: EXE_RTTI
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiPSysModifier.h"

class NiPSysVolumeEmitter : public NiPSysModifier
{
public:
    NiPSysVolumeEmitter();
    ~NiPSysVolumeEmitter() override = default;

private:
    std::uint8_t padding30[0x48];
};
static_assert(sizeof(NiPSysVolumeEmitter) == 0x78, "observed allocation size");
