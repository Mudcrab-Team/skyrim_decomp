// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa16d0 NiPSysMeshUpdateModifier::LoadBinary
// Adapted bodies: none
#include "NiPSysMeshUpdateModifier.h"

void SkipLinkIDs(NiStream* stream);

void NiPSysMeshUpdateModifier::LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    order = ORDER::kPostPosUpdate;
    return SkipLinkIDs(&stream);
}
