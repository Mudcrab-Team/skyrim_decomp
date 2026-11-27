// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject, NiAVObject::~NiAVObject, NiAVObject::GetRTTI, NiAVObject::LoadBinary, NiAVObject::LinkObject, NiAVObject::RegisterStreamables, NiAVObject::SaveBinary, NiAVObject::IsEqual, NiAVObject::ProcessClone, NiAVObject::UpdateControllers, NiAVObject::PerformOp, NiAVObject::AttachProperty, NiAVObject::SetMaterialNeedsUpdate, NiAVObject::SetDefaultMaterialNeedsUpdateFlag, NiAVObject::GetObjectByName, NiAVObject::SetSelectiveUpdateFlags, NiAVObject::UpdateDownwardPass, NiAVObject::UpdateSelectedDownwardPass, NiAVObject::UpdateRigidDownwardPass, NiAVObject::UpdateWorldBound, NiAVObject::UpdateWorldData, NiAVObject::UpdateTransformAndBounds, NiAVObject::PreAttachUpdate, NiAVObject::PostAttachUpdate, NiAVObject::OnVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiUpdateData, PerformOpFunc, NiAlphaProperty, BSFixedString, NiCullingProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNode, BSGeometry, NiSkinInstance: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the function reads
// NiAVObject::HasSkinInstanceRecursive: CRASHLOGGER_PDB(59818@2026.10.24); name only, shape from the sibling
// unknown30, unknown110, unknown124: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObjectNET.h"

class NiUpdateData;
class PerformOpFunc;
class NiAlphaProperty;
class BSFixedString;
class NiCullingProcess;

class NiAVObject : public NiObjectNET
{
public:
    ~NiAVObject() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
    virtual void UpdateControllers(NiUpdateData& a_data);  // 25
    virtual void PerformOp(PerformOpFunc& a_func);  // 26
    virtual void AttachProperty(NiAlphaProperty* a_property);  // 27
    virtual void SetMaterialNeedsUpdate(bool a_needsUpdate);  // 28
    virtual void SetDefaultMaterialNeedsUpdateFlag(bool a_flag);  // 29
    virtual NiAVObject* GetObjectByName(const BSFixedString& a_name);  // 2A
    virtual void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);  // 2B
    virtual void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // 2C
    virtual void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // 2D
    virtual void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // 2E
    virtual void UpdateWorldBound();  // 2F
    virtual void UpdateWorldData(NiUpdateData* a_data);  // 30
    virtual void UpdateTransformAndBounds(NiUpdateData& a_data);  // 31
    virtual void PreAttachUpdate(NiNode* a_parent, NiUpdateData& a_data);  // 32
    virtual void PostAttachUpdate();  // 33
    virtual void OnVisible(NiCullingProcess& a_process);  // 34
    static bool HasSkinInstanceRecursive(NiAVObject* a_object);  // compared: 0x21cd70

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown30[0xE0];  // 30
};
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject size");

class NiSkinInstance;

class BSGeometry : public NiAVObject
{
public:
    std::uint8_t unknown110[0x20];  // 110
    NiSkinInstance* skinInstance;  // 130
};

class NiNode : public NiAVObject
{
public:
    std::uint8_t unknown110[0x8];  // 110
    NiAVObject** children;  // 118
    std::uint16_t childCapacity;  // 120
    std::uint16_t childEnd;  // 122
    std::uint8_t unknown124[0x4];  // 124
};
