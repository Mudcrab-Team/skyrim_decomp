// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and sibling hints).
// Code origin: Stamped as a twin of matched 0x155780 (skyrim_shared/magic/SpellItem_1553e0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionae9b50, Ownerae9b50: GUESS(low) STANDIN
#pragma once
#include "SpellItem_1553e0.h"

class Ownerae9b50 : public MagicItem {
public:
    void SetCastingType(int value); float Functionae9b50() const; void LoadChunkDataPostProcess(InputFile* file);
private:
    std::uint8_t pad[0xd0]; int castingType; std::uint8_t gap[28]; float range; void* castingPerk;
};
