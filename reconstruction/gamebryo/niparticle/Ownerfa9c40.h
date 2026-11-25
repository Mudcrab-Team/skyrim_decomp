// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations. Stamped as a twin of matched 0xfaa390 (gamebryo/niparticle/NiPSysColorModifier): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Ownerfa9c40: GUESS(low) STANDIN
// LoadBinary, LinkObject, SaveBinary, SetLinkedObject, linkedObject, NiPSysModifier: GUESS(low) STANDIN
#pragma once
#include "NiPSysColorModifier.h"

class Ownerfa9c40 : public NiPSysModifier
{
public:
    void LoadBinary(NiStream& stream) override;
    void LinkObject(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;

private:
    void SetLinkedObject(NiAVObject* object);
    NiObject* linkedObject;
};
