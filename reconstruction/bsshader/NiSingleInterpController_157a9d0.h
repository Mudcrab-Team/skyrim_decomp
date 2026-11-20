// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: partial layouts based on the pinned field accesses and cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSingleInterpController, NiFloatInterpController, NiPoint3InterpController: STANDIN EXE_RTTI
// NiObject::LoadBinary, NiObject::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// interpolator, CopyMembers, ShaderPropertyMaterialTarget, unknown18, material, ShaderControllerColor: GUESS(low)
#pragma once

#include "gamebryo/nianimation/NiTimeController_ef7ff0.h"

class NiSingleInterpController : public NiTimeController
{
protected:
    NiInterpolator* interpolator;
};
static_assert(sizeof(NiSingleInterpController) == 0x50, "single interpolator controller size");

class NiFloatInterpController : public NiSingleInterpController
{
protected:
    void CopyMembers(NiFloatInterpController* dest);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
};

class NiPoint3InterpController : public NiSingleInterpController
{
protected:
    void CopyMembers(NiPoint3InterpController* dest);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
};

class ShaderPropertyMaterialTarget : public NiObjectNET
{
public:
    std::uint8_t unknown18[0x60];
    const std::uint8_t* material;
};
static_assert(offsetof(ShaderPropertyMaterialTarget, material) == 0x78, "observed material offset");

struct ShaderControllerColor
{
    float red;
    float green;
    float blue;
};
