// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: controller prefix and flag names follow the cited declarations and pinned accesses.
// NiTimeController: EXE_RTTI
// RegisterStreamables, Start, Stop: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CountChain, padding12, padding34: GUESS(low)
#pragma once

#include "NiInterpolator.h"

// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// text: GUESS(low); pointer to the interned text.
class BSFixedString
{
public:
    const char* text;
};

// NiObjectNET, NiObjectNET::name, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiObjectNET : public NiObject
{
public:
    BSFixedString name;
};

class NiAVObject : public NiObjectNET
{
};

// NiRTTI, NiRTTI::name, ::baseRTTI, NiRTTI_NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiRTTI
{
public:
    const char* name;
    const NiRTTI* baseRTTI;
};
extern NiRTTI NiRTTI_NiAVObject;

class NiTimeController : public NiObject
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    virtual void Start(float time);
    virtual void Stop();
    static std::uint32_t CountChain(const NiTimeController* controller);

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
static_assert(sizeof(NiTimeController) == 0x48, "time controller size");
