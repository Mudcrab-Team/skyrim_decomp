// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: partial layouts based on the pinned field accesses and cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderPropertyUShortController: EXE_RTTI
// CopyMembers, IsValidTarget, GetControlledValue, controlledVariable: GUESS(low)
// NiObject::LoadBinary, NiObject::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InitializeValueLookup: GUESS(low)
#pragma once

#include "NiSingleInterpController_157a9d0.h"

class BSLightingShaderPropertyUShortController : public NiFloatInterpController
{
public:
    void CopyMembers(BSLightingShaderPropertyUShortController* dest);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsValidTarget(const NiObjectNET* candidate) const;
    void GetControlledValue(float& value) const;
    static void InitializeValueLookup();

private:
    std::uint32_t controlledVariable;
};
