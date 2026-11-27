// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: declarations from a permitted sibling and community headers; offsets and widths checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatTrackTargetAimController: EXE_RTTI
// CombatTrackTargetAimController::LoadGame: SIBLING(fo4-private@1b765c70, author-permission)
// CombatTrackTargetAimController::fMaxDistance, CombatTrackTargetAimController::bTrackLastSeen: GUESS(medium); spelled as in the permitted sibling body, which does not declare them in a permitted file
// CombatAimController, CombatAimController::LoadGame: STANDIN EXE_RTTI; the base loader at 0x80aa70 is named by position only, header-gap CombatAimController
// BGSLoadGameBuffer, BGSLoadGameBuffer::LoadDataEndian: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the image passes a data pointer and two equal counts
// unknown08: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatAimController.cpp:294
#pragma once

#include <cstdint>

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
};

class CombatAimController
{
public:
    virtual void LoadGame(BGSLoadGameBuffer* a_buf);

    std::uint8_t unknown08[0x40];  // 08
};
static_assert(sizeof(CombatAimController) == 0x48, "CombatAimController size");

class CombatTrackTargetAimController : public CombatAimController
{
public:
    void LoadGame(BGSLoadGameBuffer* a_buf) override;

    float fMaxDistance;     // 48
    bool bTrackLastSeen;    // 4C
};
