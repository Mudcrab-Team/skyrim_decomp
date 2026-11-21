// 0x8fe0c0 ThirdPersonState::SaveGame
// Adapted bodies: none
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: ThirdPersonState::GetRotation and ::GetTranslation were adapted from the anonymous fo4-private sibling as labelled (author permission); ThirdPersonState::GetFreeRotationMode and ThirdPersonState::SaveGame were written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers.
// GetRotation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:106
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:112
// ThirdPersonState, ThirdPersonState::GetRotation, ThirdPersonState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8fd870 ThirdPersonState::GetRotation
// 0x8fd880 ThirdPersonState::GetTranslation
// 0x55d590 ThirdPersonState::GetFreeRotationMode
// Adapted bodies: GetRotation and GetTranslation (fo4-private, see the Sibling source lines)
#include "ThirdPersonState.h"

// kSaveSizePoint3, kSaveSizeWord, kSaveSizePoint2, kSaveSizeByte, kSaveCountWord, kSaveCountByte, kSaveZero: GUESS(low); the size, count and flag literals that the pinned image passes to BGSSaveGameBuffer::SaveDataEndian, named so that each call site reads as data.
constexpr std::uint32_t kSaveSizePoint3 = 0xC;
constexpr std::uint32_t kSaveSizeWord = 4;
constexpr std::uint32_t kSaveSizePoint2 = 8;
constexpr std::uint32_t kSaveSizeByte = 1;
constexpr std::uint32_t kSaveCountWord = 4;
constexpr std::uint32_t kSaveCountByte = 1;
constexpr std::uint32_t kSaveZero = 0;

void ThirdPersonState::GetRotation(NiQuaternion& value) const { value = rotation; }
void ThirdPersonState::GetTranslation(NiPoint3& value) const { value.x = translation.x; value.y = translation.y; value.z = translation.z; }
bool ThirdPersonState::GetFreeRotationMode() const { return toggleAnimCam || freeRotationEnabled || playerControls->data.fovSlideMode; }

void ThirdPersonState::SaveGame(BGSSaveFormBuffer* a_buf)
{
    a_buf->SaveDataEndian(&posOffsetExpected, kSaveSizePoint3, kSaveCountWord, kSaveZero);
    a_buf->SaveDataEndian(&targetZoomOffset, kSaveSizeWord, kSaveCountWord, kSaveZero);
    a_buf->SaveDataEndian(&freeRotation, kSaveSizePoint2, kSaveCountWord, kSaveZero);
    a_buf->SaveDataEndian(&freeRotationEnabled, kSaveSizeByte, kSaveCountByte, kSaveZero);
    a_buf->SaveDataEndian(&savedZoomOffset, kSaveSizeWord, kSaveCountWord, kSaveZero);
    a_buf->SaveString(animatedBoneName, kSaveZero);
}
