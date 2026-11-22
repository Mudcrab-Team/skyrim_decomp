// Build sse-steam-1-7-104. Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// FirstPersonState, FirstPersonState::GetTranslation, ::LoadGame, ::Revert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FirstPersonState::lastPosition, ::lastFrameSpringVelocity, ::sittingRotation, ::unk6C, ::unk70, ::currentPitchOffset, ::targetPitchOffset, ::unk7C, ::unk80, ::firstPersonCameraObj: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares unk80 as uint32, read here as a float
// FirstPersonState::unk88: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares one 8-byte unk88, the listing shows single bytes at +0x88, +0x89 and +0x8a
// FirstPersonState::unk89, ::unk8A: GUESS(low); single bytes at +0x89 and +0x8a
// NiPoint3, NiAVObject, TESCameraState, PlayerInputHandler: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3::x, ::y, ::z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLoadFormBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLoadFormBuffer::GetVersion, ::LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; LoadDataEndian takes data, size and a second count in the listing
// NiAVObject::worldTranslate: GUESS(low); the translation read at +0xa0
// niPointZero: GUESS(low); the NiPoint3 global at RVA 0x331c458, bound by the unit's bind-hints.json
#pragma once

#include <cstdint>

class NiPoint3
{
public:
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

extern "C" NiPoint3 niPointZero;

class NiAVObject
{
public:
    std::uint8_t unknown00[0xA0];  // 00
    NiPoint3 worldTranslate;       // A0
};

class BGSLoadFormBuffer
{
public:
    virtual ~BGSLoadFormBuffer();
    virtual std::uint8_t GetVersion();
    void LoadDataEndian(void* a_data, std::uint32_t a_size, std::uint32_t a_count);
};

class TESCameraState
{
public:
    virtual ~TESCameraState();
    virtual void Begin();
    virtual void End();
    virtual void Update(void* a_nextState);
    virtual void GetRotation(void* a_rotation);
    virtual void GetTranslation(NiPoint3& a_translation);
    virtual void SaveGame(void* a_buf);
    virtual void LoadGame(BGSLoadFormBuffer* a_buf);
    virtual void Revert(BGSLoadFormBuffer* a_buf);

    std::uint8_t unknown08[0x18];  // 08
};
static_assert(sizeof(TESCameraState) == 0x20, "TESCameraState size");

class PlayerInputHandler
{
public:
    virtual ~PlayerInputHandler();
    std::uint8_t unknown08[8];  // 08
};
static_assert(sizeof(PlayerInputHandler) == 0x10, "PlayerInputHandler size");

class FirstPersonState : public TESCameraState, public PlayerInputHandler
{
public:
    void GetTranslation(NiPoint3& a_translation) override;
    void LoadGame(BGSLoadFormBuffer* a_buf) override;
    void Revert(BGSLoadFormBuffer* a_buf) override;

    NiPoint3 lastPosition;             // 30
    NiPoint3 lastFrameSpringVelocity;  // 3C
    NiPoint3 dampeningOffset;          // 48
    std::uint32_t pad54;               // 54
    NiAVObject* firstPersonCameraObj;  // 58
    void* firstPersonFOVControl;       // 60
    float sittingRotation;             // 68
    float unk6C;                       // 6C
    float unk70;                       // 70
    float currentPitchOffset;          // 74
    float targetPitchOffset;           // 78
    float unk7C;                       // 7C
    float unk80;                       // 80
    bool cameraOverride;               // 84
    bool cameraPitchOverride;          // 85
    std::uint16_t pad86;               // 86
    std::uint8_t unk88;                // 88
    std::uint8_t unk89;                // 89
    std::uint8_t unk8A;                // 8A
    std::uint8_t pad8B[5];             // 8B
};
static_assert(sizeof(FirstPersonState) == 0x90, "FirstPersonState size");
