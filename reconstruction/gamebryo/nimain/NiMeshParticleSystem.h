// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header gamebryo/niparticle/NiParticleSystem.h for NiParticleSystem.
// NiMeshParticleSystem, NiMeshParticleSystem::~NiMeshParticleSystem, NiMeshParticleSystem::GetRTTI, NiMeshParticleSystem::CreateClone, NiMeshParticleSystem::LoadBinary, NiMeshParticleSystem::LinkObject, NiMeshParticleSystem::RegisterStreamables, NiMeshParticleSystem::SaveBinary, NiMeshParticleSystem::IsEqual, NiMeshParticleSystem::SetSelectiveUpdateFlags, NiMeshParticleSystem::UpdateDownwardPass, NiMeshParticleSystem::UpdateSelectedDownwardPass, NiMeshParticleSystem::UpdateRigidDownwardPass, NiMeshParticleSystem::UpdateWorldBound, NiMeshParticleSystem::UpdateWorldData, NiMeshParticleSystem::OnVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk198: GUESS(low); the eight bytes the deleting destructor frees beyond NiParticleSystem
// NiRTTI, NiCloningProcess, NiCullingProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "gamebryo/niparticle/NiParticleSystem.h"

class NiRTTI;
class NiCloningProcess;
class NiCullingProcess;

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

    std::uint64_t unk198;  // 198
};
static_assert(sizeof(NiMeshParticleSystem) == 0x1A0, "NiMeshParticleSystem size");
