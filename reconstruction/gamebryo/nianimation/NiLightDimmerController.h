// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations based on measured fields and cited interfaces.
// NiLightDimmerController: EXE_RTTI
// RegisterStreamables, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// GetTargetFade: GUESS(low)
#pragma once

#include "NiTimeController_ef7ff0.h"

// NiInterpController, NiSingleInterpController: STANDIN EXE_RTTI
class NiInterpController : public NiTimeController
{
};

class NiSingleInterpController : public NiInterpController
{
private:
    NiInterpolator* interpolator;
};
static_assert(sizeof(NiSingleInterpController) == 0x50, "single interpolator controller size");

// NiFloatInterpController: STANDIN EXE_RTTI
class NiFloatInterpController : public NiSingleInterpController
{
};

// NiLight, NiLight::fade: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiLight : public NiAVObject
{
public:
    std::uint8_t padding18[0x11c];
    float fade;
};

class NiLightDimmerController : public NiFloatInterpController
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    void GetTargetFade(float& out) const;
};
