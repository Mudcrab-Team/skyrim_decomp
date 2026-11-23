// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3ee220 TESTopic::GetDialogueSubtypeFrom4CC
// Adapted bodies: none
// TopicTypeEntry: STANDIN GUESS(low); table row with the lookup key first
// TopicTypeTable, TopicTypeEntry::type, TopicTypeEntry::unk04, kTypeCount: GUESS(low)
#include "TESTopic_3ee220.h"

struct TopicTypeEntry
{
    std::uint32_t type;
    std::uint8_t unk04[36];
};

constexpr std::uint32_t kTypeCount = 103;
extern TopicTypeEntry TopicTypeTable[kTypeCount];

// MatchIndex: GUESS(low); keep the previous result when the table row does not match.
static inline std::uint32_t MatchIndex(const TopicTypeEntry& row, std::uint32_t fourCC,
                                       std::uint32_t index, std::uint32_t previous)
{
    return row.type != fourCC ? previous : index;
}

std::uint32_t TESTopic::GetDialogueSubtypeFrom4CC(std::uint32_t fourCC)
{
    std::uint32_t result = kTypeCount;
    for (std::uint32_t index = 0; result == kTypeCount; ++index) {
        if (index >= kTypeCount) {
            break;
        }
        const TopicTypeEntry& row = TopicTypeTable[index];
        result = MatchIndex(row, fourCC, index, result);
    }
    return result;
}
