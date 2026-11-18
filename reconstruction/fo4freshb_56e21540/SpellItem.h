// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Source exposure: mixed (pinned target listing and sibling hints).
// SpellItem, SpellItem::GetRange: GUESS(low)
// SpellItem fields: STANDIN GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// InputFile: STANDIN GUESS(low)
struct InputFile { std::uint8_t pad[0x298]; std::uint16_t version; };
// MagicItem::SetCastingType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class MagicItem { public: void SetCastingType(int value); };
class SpellItem : public MagicItem {
public:
    void SetCastingType(int value); float GetRange() const; void LoadChunkDataPostProcess(InputFile* file);
private:
    std::uint8_t pad[0xd0]; int castingType; std::uint8_t gap[8]; float range; void* castingPerk;
};
