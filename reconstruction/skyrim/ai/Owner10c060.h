// Source exposure: mixed (pinned image listings and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: project ActorProcess declaration with a partial layout adapted from CommonLibSSE-NG. Stamped as a twin of matched 0x7284e0 (skyrim/ai/ActorProcess): source copied, names replaced by placeholders.
// ProcessData, padding, member: STANDIN GUESS(low)
// AIProcess::middleHigh, MagicSystem, MagicSystem::WardState, BSFaceGenAnimationData, BSFaceGenNiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function10c060, Owner10c060: GUESS(low) STANDIN
// GetEquippedLeftHand, Function7265a0, Function726fa0, Function726fc0, Function727020, Function727060, Function727080, Function7270d0, Function7270f0, Function727110, Function7271e0, Function727200, Function727220, Function727240, Function727260, Function727280, Function7272a0, Function727420, Function727440, Function727460, Function7274a0, Function727ae0, Function727b00, Function727cf0, Function727d10, Function727d30, Function727d50, Function727d70, Function727d90, Function727db0, Function727df0, Function727e10, Function727e30, Function727e50, Function727e70, Function727e90, Function727ee0, Function727f00, Function727f20, Function727f40, Function727f60, Function728500, Function728520, Function728540, Function728560, Function728580: GUESS(low) STANDIN
#pragma once
#include "ActorProcess.h"

class Owner10c060
{
public:
    virtual void* GetEquippedLeftHand() const;
    void Function7265a0();
    void Function726fa0(std::uint64_t a_value);
    std::uint64_t Function726fc0() const;
    void Function727020(bool a_value);
    void Function727060(bool a_value);
    bool Function727080() const;
    void Function7270d0(float a_value);
    float Function7270f0() const;
    void Function727110(float a_value);
    void Function7271e0();
    std::uint64_t Function727200() const;
    void Function727220(std::uint64_t a_value);
    void Function727240(bool a_value);
    bool Function727260() const;
    void Function727280(bool a_value);
    bool Function7272a0() const;
    NiNode* Function727420(std::int32_t a_index) const;
    NiAVObject* Function727440() const;
    NiAVObject* Function727460() const;
    void Function7274a0(bool a_value);
    BSFaceGenNiNode* Function727ae0() const;
    void Function727b00(BSFaceGenNiNode* a_value);
    bool Function727cf0() const;
    void Function727d10(bool a_value);
    bool Function727d30() const;
    void Function727d50(bool a_value);
    bool Function727d70() const;
    void Function727d90(bool a_value);
    void Function727db0(BSFaceGenAnimationData* a_value);
    void Function727df0(float a_value);
    float Function727e10() const;
    void Function727e30(float a_value);
    float Function727e50() const;
    void Function727e70(float a_value);
    void Function727e90(const std::uint32_t& a_value);
    bool Function727ee0() const;
    void Function727f00(bool a_value);
    bool Function727f20() const;
    void Function727f40(bool a_value);
    void Function727f60(MagicSystem::WardState a_value);
    void Function10c060();
    void Function728500();
    void Function728520();
    void Function728540();
    void Function728560();
    bool Function728580() const;
    float Function6f5220() const;
    void Function6f64b0(std::uint16_t a_action, std::uint64_t a_value);
    ObjectRefHandle& Function6f6de0(ObjectRefHandle& a_handle) const;
    void Function6f6e10(const ObjectRefHandle& a_handle, bool a_activated);
    void Function6f6f30(float a_value);
    bool Function6fe020() const;
    float Function6fe5d0() const;
    ObjectRefHandle& Function6ff4b0(ObjectRefHandle& a_handle) const;
    void Function6ff500(const ObjectRefHandle& a_handle);
    std::int32_t Function6ffe80(std::int32_t a_index) const;
    void Function6ffef0();
    bool Function720f60() const;
    bool Function7216e0() const;
    bool HasRunOncePackage() const;
    ObjectRefHandle& Function726eb0(ObjectRefHandle& a_handle) const;
    float Function7270a0() const;
    ObjectRefHandle& Function727eb0(ObjectRefHandle& a_handle) const;

    struct ProcessData;
    struct HighProcessData;
    ProcessData* middleHigh;  // 08
    HighProcessData* high;  // 10
    std::uint8_t padding[0xd8];  // 18
    void* member;
};

