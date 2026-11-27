// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: partial layouts based on the pinned field accesses and cited declarations. Stamped as a twin of matched 0x157c690 (bsshader/BSEffectShaderPropertyColorController_157c340): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject::LoadBinary, NiObject::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function10a12c0, Owner10a12c0, gEffectColorOffsets_10a12c0: GUESS(low) STANDIN
// CopyMembers, IsValidTarget, GetControlledValue, controlledVariable: GUESS(low) STANDIN
#pragma once
#include "BSEffectShaderPropertyColorController_157c340.h"

class Owner10a12c0 : public NiPoint3InterpController
{
public:
    void CopyMembers(Owner10a12c0* dest);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsValidTarget(const NiObjectNET* candidate) const;
    void GetControlledValue(ShaderControllerColor& value) const;
    static void Function10a12c0();

private:
    std::uint32_t controlledVariable;
};

