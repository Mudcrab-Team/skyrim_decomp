// 0x3a4f30 BGSRelationship::SaveGame
// Source exposure: mixed (pinned image analysis and community declarations).
// Code origin: project-authored reconstruction restored from an archived draft.
// BGSRelationship::SaveGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
#include "BGSRelationship_3a4f30.h"

bool RelationshipFlagged(void*);

void SaveHandle(void*, void*, bool);

static bool TestBit(std::uint32_t word, unsigned bit) { return (word >> bit) & 1; }

void BGSRelationship::SaveGame(BGSSaveFormBuffer* buf)
{
    TESForm::SaveGame(buf);
    if (RelationshipFlagged(this)) {
        SaveHandle(buf, unk20, false);
        SaveHandle(buf, unk28, false);
        SaveHandle(buf, unk30, false);
    }
    const auto flags = *reinterpret_cast<const std::uint32_t*>(reinterpret_cast<const std::uint8_t*>(buf) + 0x1b);
    if (TestBit(flags, 1)) buf->SaveDataEndian(&unk38, 4, 4, 0);
}
