// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations. Stamped as a twin of matched 0xfaa390 (gamebryo/niparticle/NiPSysColorModifier): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@91e1b6e src/gamebryo2.2/corelibs/niparticle/nipsyscolormodifier.cpp
// 0xfa9c40 Ownerfa9c40::SaveBinary
#include "Ownerfa9c40.h"

// guess: same compiled code as matched 0xfaa390 apart from relocated fields; its role here is not established.
void Ownerfa9c40::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    return stream.SaveLinkID(linkedObject);
}
