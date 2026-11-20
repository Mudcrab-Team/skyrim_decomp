// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: partial layouts based on the pinned field accesses and cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderPropertyFloatController: EXE_RTTI
// CopyMembers, IsValidTarget, GetControlledValue, controlledVariable: GUESS(low)
// NiObject::LoadBinary, NiObject::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiSingleInterpController_157a9d0.h"

class BSLightingShaderPropertyFloatController : public NiFloatInterpController
{
public:
    void CopyMembers(BSLightingShaderPropertyFloatController* dest);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsValidTarget(const NiObjectNET* candidate) const;
    void GetControlledValue(float& value) const;

private:
    std::uint32_t controlledVariable;
};
