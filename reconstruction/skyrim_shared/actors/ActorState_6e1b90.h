// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// ActorState: EXE_RTTI
// DoGetMovementSpeed, DoGetRotationSpeed: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class ActorState
{
public:
    float DoGetMovementSpeed() const;
    float DoGetRotationSpeed() const;
};
