// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPathController: EXE_RTTI
// unknown48, pathData, percentData: GUESS(low)
// TargetIsRequiredType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include "NiTimeController_ef7ff0.h"

class NiPathController : public NiTimeController
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void ProcessClone(NiCloningProcess& cloning) override;
    bool TargetIsRequiredType() const;

private:
    std::uint8_t unknown48[0x10];
    NiObject* pathData;
    NiObject* percentData;
};
