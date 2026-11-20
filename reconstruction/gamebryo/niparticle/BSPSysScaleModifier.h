// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysScaleModifier, SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// ParticleScaleData: STANDIN GUESS(low)
// scaleData: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class ParticleScaleData
{
public:
    void SaveBinary(NiStream& stream);
};

class BSPSysScaleModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream) override;

private:
    ParticleScaleData* scaleData;
};
