// Source exposure: mixed (pinned image, CommonLibSSE-NG, and its powerof3 counterpart checked during review).
// Code origin: HUDMeter declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HUDMeter: EXE_RTTI
// Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFillPct: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: none (declarations only).
#pragma once

class HUDMeter
{
public:
    virtual void Update();
    void SetFillPct(bool forceUpdate);
};
