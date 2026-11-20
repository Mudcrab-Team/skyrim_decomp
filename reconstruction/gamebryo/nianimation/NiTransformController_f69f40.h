// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations based on measured fields and cited interfaces.
// NiTransformController: EXE_RTTI
// IsValidTransformTarget, SupportsBlendValue: GUESS(low)
#pragma once

#include "NiTimeController_ef7ff0.h"
#include "NiBlendInterpolator.h"

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

// TransformValueSupport: STANDIN GUESS(low); extends the input interface through slot 0x30.
// NiInterpolator::IsTransformValueSupported: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TransformValueSupport : public BlendValueSupport
{
public:
    virtual bool IsTransformValueSupported() const;
};

class NiTransformController : public NiSingleInterpController
{
public:
    bool IsValidTransformTarget(const NiObjectNET* target) const;
    bool SupportsBlendValue(const TransformValueSupport* input, std::uint16_t) const;
};
