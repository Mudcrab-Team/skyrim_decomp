// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xf145f0 NiParticlesData::NiParticlesData
#include "NiParticlesData_f145f0.h"

// Initializes particle geometry data fields, bounds, and default unit scale values.
NiParticlesData::NiParticlesData() :
    unk12(0),
    boundCenter(NiPoint3::ZERO),
    boundRadius(0.0f),
    unk28(0),
    unk30(0),
    unk38(0),
    unk40(0),
    unk48(0),
    unk50(0),
    unk58(0),
    unk60(0),
    unk68(0),
    unk6C(1.0f),
    unk70(1.0f),
    unk74(1.0f),
    unk78(1.0f),
    unk7C(0),
    unk80(0),
    unk88(0)
{
    unk10 = false;
}
