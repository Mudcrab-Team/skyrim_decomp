// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: partial layouts based on the pinned field accesses and cited declarations. Stamped as a twin of matched 0x157c690 (bsshader/BSEffectShaderPropertyColorController_157c340): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject::LoadBinary, NiObject::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functioneb7490, Ownereb7490, gEffectColorOffsets_eb7490: GUESS(low) STANDIN
// CopyMembers, IsValidTarget, GetControlledValue, controlledVariable: GUESS(low) STANDIN
#pragma once
#include "BSEffectShaderPropertyColorController_157c340.h"

class Ownereb7490 : public NiPoint3InterpController
{
public:
    void CopyMembers(Ownereb7490* dest);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsValidTarget(const NiObjectNET* candidate) const;
    void GetControlledValue(ShaderControllerColor& value) const;
    static void Functioneb7490();

private:
    std::uint32_t controlledVariable;
};

