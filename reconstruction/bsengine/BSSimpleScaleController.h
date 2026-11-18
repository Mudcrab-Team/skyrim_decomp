// Code origin: names, bases, slot order and member layout adapted from CharmedBaryon/CommonLibSSE-NG (MIT)
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSimpleScaleController, BSSimpleScaleController::TargetIsRequiredType, BSSimpleScaleController::~BSSimpleScaleController, BSSimpleScaleController::GetRTTI, BSSimpleScaleController::CreateClone, BSSimpleScaleController::Update, NiTimeController::~NiTimeController, NiTimeController::GetRTTI, NiTimeController::LoadBinary, NiTimeController::LinkObject, NiTimeController::RegisterStreamables, NiTimeController::SaveBinary, NiTimeController::IsEqual, NiTimeController::ProcessClone, NiTimeController::Start, NiTimeController::Stop, NiTimeController::Update, NiTimeController::SetTarget, NiTimeController::IsTransformController, NiTimeController::IsVertexController, NiTimeController::ComputeScaledTime, NiTimeController::OnPreDisplay, NiTimeController::IsStreamable, NiTimeController::TargetIsRequiredType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTimeController, NiObjectNET: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTimeController::flags, frequency, phase, loKeyTime, hiKeyTime, startTime, lastTime, weightedLastTime, scaledTime, target, next, BSSimpleScaleController::scale3D, refScale, scaleAnimDuration, NiRTTI::name, NiRTTI_NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiRTTI::parent: OBSERVED; NiRTTI_NiAVObject is the runtime type object that the image's NiNode type object names as its parent
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

// Runtime type object for NiAVObject (address 0x331c4a8), defined elsewhere.
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

class BSSimpleScaleController : public NiTimeController
{
public:
    ~BSSimpleScaleController() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void Update(float a_time) override;  // 27
    bool TargetIsRequiredType() const override;  // 2E, compared: 0x7384e0

    float scale3D;  // 48
    float refScale;  // 4C
    float scaleAnimDuration;  // 50
    std::uint32_t pad54;  // 54
};
static_assert(sizeof(BSSimpleScaleController) == 0x58, "BSSimpleScaleController size");
static_assert(offsetof(NiTimeController, target) == 0x38, "target offset");
