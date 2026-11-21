// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0x282160 TESObjectCONT::HandleClose
// Adapted bodies: none
#include "TESObjectCONT_282160.h"

void TESObjectCONT::HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator)
{
	ContainerFunction282480(closeSound, a_target, this);
}
