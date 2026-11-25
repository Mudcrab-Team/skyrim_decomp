// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatMeleeAimController, CombatAimController: EXE_RTTI
// BGSLoadGameBuffer, BGSLoadGameBuffer::LoadDataEndian: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; only the one call the compared code makes, with the argument list the image passes
// CombatAimController::LoadGame, CombatMeleeAimController::LoadGame: SIBLING(fo4-private@1b765c70, author-permission)
// fMinDistance: SYMBOLS(fo4-pdb)
// unk4C, unk50, unk54: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

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
static_assert(sizeof(CombatAimController) == 0x48, "CombatAimController stand-in size");

class CombatMeleeAimController : public CombatAimController
{
public:
    void LoadGame(BGSLoadGameBuffer* a_buf) override;  // compared: 0x80b5d0

    float fMinDistance;  // 48
    std::uint8_t unk4C;  // 4C
    std::uint32_t unk50;  // 50
    std::uint32_t unk54;  // 54
};
static_assert(sizeof(CombatMeleeAimController) == 0x58, "CombatMeleeAimController size");
