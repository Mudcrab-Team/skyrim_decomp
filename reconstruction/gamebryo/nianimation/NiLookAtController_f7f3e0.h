// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation and partial layouts from the pinned accesses and cited declarations.
// NiLookAtController: EXE_RTTI
// LinkObject, RegisterStreamables, TargetIsRequiredType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// lookAt, padding48: GUESS(low)
#pragma once

#include "NiSingleInterpController_f62ff0.h"

// NiRTTI, NiRTTI::name, ::baseRTTI, NiRTTI_NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiRTTI
{
public:
    const char* name;
    const NiRTTI* baseRTTI;
};
extern NiRTTI NiRTTI_NiAVObject;

class NiLookAtController : public NiTimeController
{
public:
    NiLookAtController();
    void LinkObject(NiStream& stream) override;
    bool RegisterStreamables(NiStream& stream) override;
    ~NiLookAtController() override = default;
    bool TargetIsRequiredType() const override;

private:
    std::uint8_t padding48[0x8];
    NiObject* lookAt;
};
