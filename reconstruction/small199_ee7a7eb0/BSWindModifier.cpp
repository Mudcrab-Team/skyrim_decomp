// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfd8ba0 BSWindModifier::Functionfd8ba0
#include "BSWindModifier.h"
void BSWindModifier::CopyMembers(BSWindModifier* a_dest)
{
    CopyBase(this, a_dest);
    a_dest->strength = strength;
}
