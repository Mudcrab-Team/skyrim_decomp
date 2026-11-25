// Source exposure: mixed (community declarations; target observations; sibling-symbol layout).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa65c0 NiPSysAgeDeathModifier::SaveBinary
// Adapted bodies: none; serialization call shape independently reconstructed from target observations
#include "NiPSysAgeDeathModifier_fa65c0.h"

void NiPSysAgeDeathModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    stream.oStr->PutBool(m_bSpawnOnDeath);
    stream.SaveLinkID(m_pkSpawnModifier);
}
