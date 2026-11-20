// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation and partial layouts from the pinned accesses and cited declarations.
// NiExtraDataController: EXE_RTTI
// LinkObject, RegisterStreamables, SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// extraDataName, extraData: GUESS(low)
#pragma once

#include "NiSingleInterpController_f62ff0.h"

class NiExtraDataController : public NiSingleInterpController
{
public:
    void LinkObject(NiStream& stream) override;
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    NiExtraDataController();

private:
    BSFixedString extraDataName;
    NiObject* extraData;
};
