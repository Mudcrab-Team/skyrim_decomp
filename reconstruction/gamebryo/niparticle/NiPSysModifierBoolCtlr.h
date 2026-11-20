// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the existing blend support declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifierBoolCtlr, InterpolatorIsCorrectType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// IsBoolValueSupported: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BlendValueSupport;

class NiPSysModifierBoolCtlr
{
public:
    bool InterpolatorIsCorrectType(const BlendValueSupport* input, std::uint16_t index) const;
};
