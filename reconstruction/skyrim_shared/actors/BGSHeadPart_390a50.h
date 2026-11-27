// Source exposure: mixed (pinned image, cited public declarations and the 2013 map).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: declarations follow the cited community header; the static's signature follows the pinned code.
// BGSHeadPart, BGSHeadPart::HeadPartType, ::kMisc, ::kFace, ::kEyes, ::kHair, ::kFacialHair, ::kScar, ::kEyebrows: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSHeadPart::GetMustHeadPartBeUnique: SYMBOLS(tesv-2013-map)
#pragma once

class BGSHeadPart
{
public:
    enum class HeadPartType
    {
        kMisc = 0x0,
        kFace = 0x1,
        kEyes = 0x2,
        kHair = 0x3,
        kFacialHair = 0x4,
        kScar = 0x5,
        kEyebrows = 0x6
    };

    static bool GetMustHeadPartBeUnique(HeadPartType a_type);
};
