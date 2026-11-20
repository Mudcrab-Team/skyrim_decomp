// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation and partial layouts from the pinned accesses and cited declarations.
// GPL-3.0 declaration source for NiTimeController::SetNext is cited below.
// NiSingleInterpController: EXE_RTTI
// GetInterpolatorIndexFx, ResetTimeExtrema, GuaranteeTimeRange, TargetIsRequiredType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiTimeController::SetNext: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// IsValidTarget, interpolator, padding: GUESS(low)
#pragma once

#include "NiInterpolator.h"


// BSFixedString, NiObjectNET, NiObjectNET::name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// text: GUESS(low); pointer to the interned name.
class BSFixedString
{
public:
    const char* text;
};

class NiObjectNET : public NiObject
{
public:
    BSFixedString name;
};

// ControllerInterpolator: STANDIN GUESS(low); only the two timing operations are called here.
// NiInterpolator::GetActiveTimeRange, ::GuaranteeTimeRange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class ControllerInterpolator : public NiObject
{
public:
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();

    virtual void GetActiveTimeRange(float& start, float& end) const;
    virtual void GuaranteeTimeRange(float start, float end);
};

// NiTimeController, NiInterpController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiTimeController : public NiObject
{
public:
    NiTimeController();
    ~NiTimeController() override;
    void LinkObject(NiStream& stream) override;
    bool RegisterStreamables(NiStream& stream) override;
    virtual void Start(float time);
    virtual void Stop();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual bool TargetIsRequiredType() const;
    void SetNext(NiTimeController* successor);

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

class NiInterpController : public NiTimeController
{
public:
    NiInterpController();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual std::uint16_t GetInterpolatorIndexFx(const BSFixedString& id) const;
    virtual void Slot33();
    virtual void Slot34();
    virtual void ResetTimeExtrema();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void GuaranteeTimeRange(float start, float end);
    virtual void Slot3B();
};
static_assert(sizeof(NiInterpController) == 0x48, "interpolator controller size");

class NiSingleInterpController : public NiInterpController
{
public:
    void LinkObject(NiStream& stream) override;
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    NiSingleInterpController();
    virtual bool IsValidTarget(const NiObjectNET* object) const;
    std::uint16_t GetInterpolatorIndexFx(const BSFixedString& id) const override;
    void GuaranteeTimeRange(float start, float end) override;
    bool TargetIsRequiredType() const override;

private:
    ControllerInterpolator* interpolator;
};
