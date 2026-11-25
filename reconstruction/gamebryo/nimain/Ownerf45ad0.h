// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations. Stamped as a twin of matched 0xf10f30 (gamebryo/nimain/NiFloatExtraData_f10eb0): source copied, names replaced by placeholders.
// ::SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Ownerf45ad0: GUESS(low) STANDIN
#pragma once
#include "NiFloatExtraData_f10eb0.h"

class Ownerf45ad0 : public NiExtraData
{
public:
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;

private:
    float value;
};

