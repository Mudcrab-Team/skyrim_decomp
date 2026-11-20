// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiFloatExtraData: EXE_RTTI
// NiFloatExtraData::LoadBinary, ::SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiFloatExtraData::value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiExtraData_ef9840.h"

class NiFloatExtraData : public NiExtraData
{
public:
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;

private:
    float value;
};
