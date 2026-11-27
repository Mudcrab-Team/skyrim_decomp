// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: names, bases, slot order and the NiTimeController layout adapted from CharmedBaryon/CommonLibSSE-NG (MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLagBoneController, BSLagBoneController::TargetIsRequiredType: EXE_RTTI; the class owning the compared virtual, slot 2E overriding the community base slot
// NiTimeController, NiTimeController::~NiTimeController, NiTimeController::GetRTTI, NiTimeController::LoadBinary, NiTimeController::LinkObject, NiTimeController::RegisterStreamables, NiTimeController::SaveBinary, NiTimeController::IsEqual, NiTimeController::ProcessClone, NiTimeController::Start, NiTimeController::Stop, NiTimeController::Update, NiTimeController::SetTarget, NiTimeController::IsTransformController, NiTimeController::IsVertexController, NiTimeController::ComputeScaledTime, NiTimeController::OnPreDisplay, NiTimeController::IsStreamable, NiTimeController::TargetIsRequiredType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObjectNET: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTimeController::flags, pad12, pad34, frequency, phase, loKeyTime, hiKeyTime, startTime, lastTime, weightedLastTime, scaledTime, target, next, NiRTTI::name, NiRTTI_NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRTTI::parent: OBSERVED; the kind-of walk follows the parent type
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"
#include "declarations/NiObjectNET.h"

class NiObjectNET;

// Runtime type descriptor: a name and the parent type, which the kind-of walk follows.
class NiRTTI
{
public:
    const char* name;  // 00
    const NiRTTI* parent;  // 08
};
static_assert(sizeof(NiRTTI) == 0x10, "NiRTTI size");

// Runtime type object for NiAVObject, defined elsewhere.
extern NiRTTI NiRTTI_NiAVObject;

class NiTimeController : public NiObject
{
public:
    ~NiTimeController() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
    virtual void Start(float a_time);  // 25
    virtual void Stop();  // 26
    virtual void Update(float a_time) = 0;  // 27
    virtual void SetTarget(NiObjectNET* a_target);  // 28
    virtual bool IsTransformController() const;  // 29
    virtual bool IsVertexController() const;  // 2A
    virtual float ComputeScaledTime(float a_time);  // 2B
    virtual void OnPreDisplay();  // 2C
    virtual bool IsStreamable() const;  // 2D
    virtual bool TargetIsRequiredType() const = 0;  // 2E
    std::uint16_t flags;  // 10
    std::uint16_t pad12;  // 12
    float frequency;  // 14
    float phase;  // 18
    float loKeyTime;  // 1C
    float hiKeyTime;  // 20
    float startTime;  // 24
    float lastTime;  // 28
    float weightedLastTime;  // 2C
    float scaledTime;  // 30
    std::uint32_t pad34;  // 34
    NiObjectNET* target;  // 38
    NiTimeController* next;  // 40, NG: NiPointer<NiTimeController>
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");
static_assert(offsetof(NiTimeController, target) == 0x38, "target offset");

// Only the compared virtual is modelled; the derived layout is not needed by it.
class BSLagBoneController : public NiTimeController
{
public:
    bool TargetIsRequiredType() const override;  // 2E, compared: 0x10049f0
};
