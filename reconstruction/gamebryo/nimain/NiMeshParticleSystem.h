// Source exposure: mixed (community declarations and the pinned image).
// Code origin: existing unit plus original reconstruction of Functionf9e800.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiMeshParticleSystem, ~NiMeshParticleSystem, GetRTTI, CreateClone, LoadBinary, LinkObject, RegisterStreamables, SaveBinary, IsEqual, SetSelectiveUpdateFlags, UpdateDownwardPass, UpdateSelectedDownwardPass, UpdateRigidDownwardPass, UpdateWorldBound, UpdateWorldData, OnVisible, NiParticlesData, NiRTTI, NiCloningProcess, NiCullingProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MeshParticleTarget, Functionf9e800, unk198, unknown00, target: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "gamebryo/niparticle/NiParticleSystem.h"

class NiRTTI;
class NiCloningProcess;
class NiCullingProcess;

class MeshParticleTarget
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
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
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
};

class NiParticlesData
{
public:
    std::uint8_t unknown00[0xA8];
    MeshParticleTarget* target;
};

class NiMeshParticleSystem : public NiParticleSystem
{
public:
    // noinline: the deleting destructor must call the out-of-line destructor
    virtual __declspec(noinline) ~NiMeshParticleSystem();  // compared: 0xf9eb30  // slot 00
    const NiRTTI* GetRTTI() const;  // 02
    NiObject* CreateClone(NiCloningProcess& a_cloning);  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;  // 2B
    void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2C
    void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2D
    void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // 2E
    void UpdateWorldBound();  // 2F
    void UpdateWorldData(NiUpdateData* a_data);  // 30
    void OnVisible(NiCullingProcess& a_process);  // 34
    NiMeshParticleSystem();
    void Functionf9e800();

    std::uint64_t unk198;  // 198
};
static_assert(sizeof(NiMeshParticleSystem) == 0x1A0, "NiMeshParticleSystem size");
