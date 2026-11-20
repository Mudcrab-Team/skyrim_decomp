// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations based on measured fields and cited interfaces.
// NiMultiTargetTransformController: EXE_RTTI
// GetInterpolatorIndexFx, GetInterpolator, CreateBlendInterpolator, TargetIsRequiredType, InterpolatorIsCorrectType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiMultiTargetTransformController::blendInterps, ::targets, ::numInterps: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiTimeController_ef7ff0.h"
#include "NiBlendInterpolator.h"

// NiInterpController, NiBlendTransformInterpolator: STANDIN EXE_RTTI
class NiInterpController : public NiTimeController
{
};

class NiBlendTransformInterpolator : public NiBlendInterpolator
{
};
static_assert(sizeof(NiBlendTransformInterpolator) == 0x48, "transform blend element stride");

// TransformValueSupport: STANDIN GUESS(low); extends the input interface through slot 0x30.
// NiInterpolator::IsTransformValueSupported: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TransformValueSupport : public BlendValueSupport
{
public:
    virtual bool IsTransformValueSupported() const;
};

class NiMultiTargetTransformController : public NiInterpController
{
public:
    std::uint16_t GetInterpolatorIndexFx(const BSFixedString& id) const;
    NiInterpolator* GetInterpolator(std::uint16_t index) const;
    NiBlendInterpolator* CreateBlendInterpolator(std::uint16_t index, bool, bool, float, std::uint8_t) const;
    bool TargetIsRequiredType() const;
    bool InterpolatorIsCorrectType(const TransformValueSupport* input, std::uint16_t) const;

private:
    NiBlendTransformInterpolator* blendInterps;
    NiAVObject** targets;
    std::uint16_t numInterps;
};
static_assert(sizeof(NiMultiTargetTransformController) == 0x60, "multi-target controller size");
