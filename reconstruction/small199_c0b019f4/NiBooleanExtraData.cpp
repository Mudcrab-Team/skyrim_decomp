// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf0fe40 NiBooleanExtraData::Functionf0fe40
#include "NiBooleanExtraData.h"
void NiBooleanExtraData::CopyMembers(NiBooleanExtraData* a_dest)
{
    CopyBase(this, a_dest);
    a_dest->data = data;
}
