// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// NiStringExtraData: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xef70a0 NiStringExtraData::Functionef70a0
#include "NiStringExtraData.h"
void NiStringExtraData::Functionef70a0(NiStringExtraData* target) {
 CopyBase(target);
 CopyString(&target->value, &value);
}
