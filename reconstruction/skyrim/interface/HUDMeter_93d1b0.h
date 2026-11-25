// Source exposure: mixed (pinned image and CommonLibSSE-NG).
// Code origin: original reconstruction using the family generator and community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HUDMeter: EXE_RTTI
// Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFillPct: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: HUDMeter::Update, CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/H/HUDMeter.cpp (MIT).
#pragma once

class HUDMeter
{
public:
    virtual void Update();
    void SetFillPct(bool forceUpdate);
};
