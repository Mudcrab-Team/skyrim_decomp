// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the body is the compiler-generated scalar deleting destructor from the listing
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

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0xA8];  // 10
};
static_assert(sizeof(NiControllerSequence) == 0xB8, "NiControllerSequence size");
