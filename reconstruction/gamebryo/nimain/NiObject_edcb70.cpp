// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: GetStreamableRTTI follows CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiObject.h:75 (MIT).
// 0xedcb70 NiObject::GetStreamableRTTI
#include "NiObject_edcb70.h"

const NiRTTI* NiObject::GetStreamableRTTI() const
{
    return GetRTTI();
}
