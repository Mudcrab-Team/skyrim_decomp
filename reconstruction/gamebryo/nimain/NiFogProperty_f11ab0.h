// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFogProperty: EXE_RTTI
// ReleaseDefault, gDefaultFogProperty: GUESS(low)
// NiProperty: STANDIN EXE_RTTI
// CopyMembers, fogFlags, unknown34, FogColor, color38, color44, red, green, blue: GUESS(low)
#pragma once

#include "NiObjectNET.h"

class NiProperty : public NiObjectNET
{
public:
    void CopyMembers(NiProperty* dest);
};

struct FogColor
{
    float red;
    float green;
    float blue;
};

class NiFogProperty : public NiProperty
{
public:
    static void ReleaseDefault();
    void CopyMembers(NiFogProperty* dest);

private:
    std::uint16_t fogFlags;
    float unknown34;
    FogColor color38;
    FogColor color44;
};
