// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG at the pin below.
// Source exposure: mixed (local binary analysis and public declarations).
// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// BSExtraData, next, ExtraAction, action, ExtraDataList, GetByType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
class ExtraAction : public BSExtraData { public: std::int8_t action; };
class ExtraDataList { public:
    BSExtraData* GetByType(std::uint32_t type);
    // ReadActionFlags: GUESS(low)
    std::uint32_t ReadActionFlags();
};
