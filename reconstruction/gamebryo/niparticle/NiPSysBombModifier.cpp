// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa6e10 NiPSysBombModifier::LinkObject
// Adapted bodies: the FNV body named by the Sibling source line above.
// Sibling source: momusdigital/fnv_decomp@91e1b6e src/gamebryo2.2/corelibs/niparticle/nipsysgravitymodifier.cpp
// LinkObject: SIBLING(momusdigital/fnv_decomp@91e1b6e, no-licence)
#include "NiPSysBombModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysBombModifier::NiPSysBombModifier() = default;

void NiPSysBombModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    linkedObject = stream.ReadLinkID();
}
