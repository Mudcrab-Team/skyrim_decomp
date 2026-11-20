// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// NiObject: EXE_RTTI
// GetStreamableRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function01: GUESS(low)
#pragma once

#include <cstdint>

class NiRTTI;

class NiObject
{
public:
    virtual ~NiObject();
    virtual void Function01();  // 01
    virtual const NiRTTI* GetRTTI() const;  // 02
    const NiRTTI* GetStreamableRTTI() const;
};
