// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/NiObject.h for NiObject.
// NiControllerSequence, NiControllerSequence::~NiControllerSequence, NiControllerSequence::GetRTTI, NiControllerSequence::CreateClone, NiControllerSequence::LoadBinary, NiControllerSequence::LinkObject, NiControllerSequence::RegisterStreamables, NiControllerSequence::SaveBinary, NiControllerSequence::IsEqual, NiControllerSequence::ProcessClone, NiControllerSequence::PostLinkObject, NiControllerSequence::Deactivate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class NiControllerSequence : public NiObject
{
public:
    virtual ~NiControllerSequence();  // compared: 0xf5b4e0  // slot 00
    const NiRTTI* GetRTTI() const override;  // 02
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
    void PostLinkObject(NiStream& a_stream) override;  // 1E
    virtual bool Deactivate(float a_easeOutTime, bool a_transition);  // 25
    NiControllerSequence();

    // unknown10: GUESS(low); the layout after the NiObject base, not read by the compared destructor
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
    std::uint64_t unknown80;  // 80
    std::uint64_t unknown88;  // 88
    std::uint64_t unknown90;  // 90
    std::uint64_t unknown98;  // 98
    std::uint64_t unknownA0;  // A0
    std::uint64_t unknownA8;  // A8
    std::uint64_t unknownB0;  // B0
};
static_assert(sizeof(NiControllerSequence) == 0xB8, "NiControllerSequence size");
