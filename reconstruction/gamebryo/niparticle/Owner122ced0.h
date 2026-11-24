// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0xfa11c0 (gamebryo/niparticle/NiPSysModifier): source copied, names replaced by placeholders.
// Adapted code: the NiBinaryStream ReadFn and WriteFn aliases and the read, write and put template bodies are adapted from NG b93280e include/RE/N/NiBinaryStream.h and src/RE/N/NiBinaryStream.cpp under its MIT licence: put is NG's body; read and write fold in NG's binary_read and binary_write and return true instead of comparing the byte count.
// The bodies of LinkObject, RegisterStreamables and ProcessClone in NiPSysModifier.cpp closely parallel the same methods in momusdigital/fnv_decomp 91e1b6e8 (no licence; used by maintainer
// decision, docs/authorizations.md); the Sibling source lines there name the files. Bodies
// adapted from community sources are listed above; tools/check_origin.py reports none other above its threshold (0.75) at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8. NG's licence notice, from its LICENSE at b93280e, is kept as it requires:
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream, NiCloningProcess, BSFixedString, NiParticleSystem, NiPSysData, NiPoint3, NiColorA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members and slots the unit uses
// Owner122ced0: GUESS(low) STANDIN
// NiObject, name, order, target, active, pad1C, pad29, Update, Initialize, HandleReset, SetActive, SetSystemPointer: GUESS(low) STANDIN
#pragma once
#include "NiPSysModifier.h"
#include <intrin.h>
#include <cstdint>
#include <new>

class Owner122ced0 : public NiObject {
public:
    ~Owner122ced0() override;
    void GetRTTI() override;                            // 02
    void LoadBinary(NiStream& a_stream) override;       // 18
    void LinkObject(NiStream& a_stream) override;       // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;       // 1B
    bool IsEqual(NiObject* a_object) override;          // 1C
    void ProcessClone(NiCloningProcess& a_cloning) override;  // 1D

    virtual bool Update(float a_time, NiPSysData* a_particleData, NiPoint3* a_position, NiPoint3* a_radii, NiColorA* a_rotation) = 0;  // 25
    virtual void Initialize(NiPSysData* a_particleData, std::uint16_t, NiPoint3*);  // 26
    virtual void HandleReset();                                                      // 27
    virtual void SetActive(bool a_active);                                           // 28
    virtual void SetSystemPointer(NiParticleSystem* a_target);                       // 29

    BSFixedString     name;      // 10
    ORDER             order;     // 18
    std::uint32_t     pad1C;     // 1C
    NiParticleSystem* target;    // 20
    bool              active;    // 28
    std::uint8_t      pad29[7];  // 29
};
static_assert(sizeof(Owner122ced0) == 0x30, "size from the deleting destructor");
