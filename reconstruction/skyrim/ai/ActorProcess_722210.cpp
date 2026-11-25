// Source exposure: mixed (local target analysis and permitted name/layout references).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original body and minimal intrusive assignment helper.
// 0x722210 ActorProcess::GetRagdollPenetrationUtil
#include "ActorProcess_722210.h"

bool ActorProcess::GetRagdollPenetrationUtil(PenetrationPointer& output) const
{
    const PenetrationPointer empty;
    output.Assign(middleHigh ? middleHigh->penetrationDetectUtil : empty);
    return output.pointer != nullptr;
}
