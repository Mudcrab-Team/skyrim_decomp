// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysInheritVelocityModifier, LinkObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// linkedObject: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class BSPSysInheritVelocityModifier : public NiPSysModifier
{
public:
    void LinkObject(NiStream& stream) override;

private:
    NiAVObject* linkedObject;
};
