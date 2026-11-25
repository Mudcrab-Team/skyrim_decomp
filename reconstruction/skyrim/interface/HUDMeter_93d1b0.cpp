// Source exposure: mixed (pinned image, CommonLibSSE-NG, and its powerof3 counterpart checked during review).
// Code origin: HUDMeter::Update adapted from the MIT-licensed CommonLibSSE-NG implementation.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HUDMeter: EXE_RTTI
// Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFillPct: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: HUDMeter::Update, CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/H/HUDMeter.cpp:15 (MIT).
// The identical body also appears in powerof3/CommonLibSSE@654e55f src/RE/H/HUDMeter.cpp:15 (GPL-3.0 fork).
// 0x93d1b0 HUDMeter::Update
// CI hash: 0x93d1b0 ?Update@HUDMeter@@UEAAXXZ
#include "HUDMeter_93d1b0.h"

void HUDMeter::Update()
{
    SetFillPct(false);
}
