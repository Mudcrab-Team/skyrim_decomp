// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf10e80 NiFloatExtraData::Functionf10e80
#include "NiFloatExtraData_f10e80.h"
void NiFloatExtraData::CopyMembers(NiFloatExtraData* a_dest)
{
    CopyBase(this, a_dest);
    a_dest->value = value;
}
