// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// FurnitureCameraState, FurnitureCameraState::GetTranslation, FurnitureCameraState::~FurnitureCameraState, FurnitureCameraState::Begin, FurnitureCameraState::End, FurnitureCameraState::Update, FurnitureCameraState::GetRotation: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// TESCameraState, TESCameraState::~TESCameraState, TESCameraState::Begin, TESCameraState::End, TESCameraState::Update, TESCameraState::GetRotation, TESCameraState::GetTranslation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3, NiQuaternion, NiMatrix3, BSTSmartPointer, TESCameraState: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); main's TESCameraState.h declares a different virtual order, and the compared body calls slot 04 here
// NiPoint3::x, NiPoint3::y, NiPoint3::z, NiQuaternion::w, NiQuaternion::x, NiQuaternion::y, NiQuaternion::z, NiMatrix3::entry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08, unknown10, unknown18, unknown20, unknown28, unknown30, unknown38: GUESS(low); the compared body reads none of them
// QuaternionToMatrix, GetTranslationFromMatrix: GUESS(low); callees declared only
#pragma once

#include <cstdint>
#include <cstddef>

template <class T>
class BSTSmartPointer;

class NiPoint3
{
public:
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class NiQuaternion
{
public:
    float w;  // 00
    float x;  // 04
    float y;  // 08
    float z;  // 0C
};
static_assert(sizeof(NiQuaternion) == 0x10, "NiQuaternion size");

class NiMatrix3
{
public:
    float entry[3][3];  // 00
};
static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 size");

void QuaternionToMatrix(const NiQuaternion& a_rotation, NiMatrix3& a_matrix);

class TESCameraState
{
public:
    virtual ~TESCameraState();  // 00
    virtual void Begin();  // 01
    virtual void End();  // 02
    virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState);  // 03
    virtual void GetRotation(NiQuaternion& a_rotation);  // 04
    virtual void GetTranslation(NiPoint3& a_translation);  // 05

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
};
static_assert(sizeof(TESCameraState) == 0x20, "TESCameraState size");

class FurnitureCameraState : public TESCameraState
{
public:
    ~FurnitureCameraState() override;  // 00
    void Begin() override;  // 01
    void End() override;  // 02
    void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
    void GetRotation(NiQuaternion& a_rotation) override;  // 04
    virtual void GetTranslation(NiPoint3& a_translation);  // compared: 0x8f6960  // slot 05
    void GetTranslationFromMatrix(NiPoint3& a_translation, const NiMatrix3& a_matrix);  // 06

    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
};
static_assert(sizeof(FurnitureCameraState) == 0x40, "FurnitureCameraState size");
