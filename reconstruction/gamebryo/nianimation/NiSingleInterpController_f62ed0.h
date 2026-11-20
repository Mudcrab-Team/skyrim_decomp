// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial controller layouts and stream virtual slots follow the cited public declarations and pinned accesses.
// NiSingleInterpController: EXE_RTTI
// NiInterpController, NiTimeController, NiObject, NiInterpolator, NiStream, NiObjectNET: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RegisterStreamables, SaveBinary, ProcessClone, SetInterpolator: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// interpolator, padding12, padding34: GUESS(low)
#pragma once

#include "NiInterpolator.h"

// Field names follow NiTimeController in CommonLibSSE-NG at b93280e.
class NiTimeController : public NiObject
{
public:
    void ProcessClone(NiCloningProcess& cloning) override;

protected:
    std::uint16_t flags;
    std::uint16_t padding12;
    float frequency;
    float phase;
    float loKeyTime;
    float hiKeyTime;
    float startTime;
    float lastTime;
    float weightedLastTime;
    float scaledTime;
    std::uint32_t padding34;
    NiObjectNET* target;
    NiTimeController* next;
};
static_assert(sizeof(NiTimeController) == 0x48, "controller prefix size");

class NiInterpController : public NiTimeController
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
};

class NiSingleInterpController : public NiInterpController
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    void SetInterpolator(NiInterpolator* value, std::uint16_t index);
    void ProcessClone(NiCloningProcess& cloning) override;

private:
    NiInterpolator* interpolator;
};
static_assert(sizeof(NiSingleInterpController) == 0x50, "single interpolator controller size");
