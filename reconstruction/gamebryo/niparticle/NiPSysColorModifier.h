// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysColorModifier, LoadBinary, LinkObject, SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// SetLinkedObject, linkedObject: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysColorModifier : public NiPSysModifier
{
public:
    void LoadBinary(NiStream& stream) override;
    void LinkObject(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;

private:
    void SetLinkedObject(NiAVObject* object);
    NiObject* linkedObject;
};
