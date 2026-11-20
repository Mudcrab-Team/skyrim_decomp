// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// Adapted bodies: SetEnabled and GetCurrentStageID follow CommonLibSSE-NG@b93280e src/RE/T/TESQuest.cpp:91 and :25 (MIT).
// 0x3d0390 TESQuest::SetEnabled
// 0x3d0720 TESQuest::IsActive
// 0x3d0740 TESQuest::Function3d0740
// 0x3d1220 TESQuest::GetCurrentStageID
// 0x3d1630 TESQuest::Function3d1630
// 0x3d1670 TESQuest::Function3d1670
// 0x3d16a0 TESQuest::Function3d16a0
// 0x3d17a0 TESQuest::AcceptVisitor
// 0x3d3220 TESQuest::Function3d3220
// 0x3d88c0 TESQuest::Function3d88c0
// 0x3d8ac0 TESQuest::Function3d8ac0
// 0x3d8b10 TESQuest::Function3d8b10
#include "TESQuest_3d0390.h"

// questInstanceValue, invalidQuestInstanceValue, Function3d86b0: GUESS(low)
extern std::uint32_t questInstanceValue;
extern const std::uint32_t invalidQuestInstanceValue;
void Function3d86b0();

void TESQuest::SetEnabled(bool enabled)
{
    if (enabled) {
        data.flags |= 1u;
    } else {
        data.flags &= ~1u;
    }
    return static_cast<void>(AddChange(1u << 1));
}

bool TESQuest::IsActive() const
{
    return (data.flags >> 11) & 1u;
}

void TESQuest::Function3d0740(bool active)
{
    const auto flags = data.flags;
    data.flags = active ? flags | (1u << 11) : flags & ~(1u << 11);
}

std::uint16_t TESQuest::GetCurrentStageID() const
{
    return currentStage;
}

std::int32_t TESQuest::Function3d1630(const bool* start, BGSScene* scene)
{
    if (scene && (!*start || (scene->flags & 1u))) {
        scene->Function3a8060(*start);
    }
    return 1;
}

std::int32_t TESQuest::Function3d1670(const void*, BGSScene* scene)
{
    if (scene && scene->isPlaying) {
        scene->Function3a7970();
    }
    return 1;
}

std::int32_t TESQuest::Function3d16a0(const std::uint32_t* action, BGSScene* scene)
{
    if (scene && scene->isPlaying) {
        scene->Function3a8830(*action);
    }
    return 1;
}

BGSStoryManagerTreeVisitor::VisitControl TESQuest::AcceptVisitor(BGSStoryManagerTreeVisitor& visitor)
{
    return visitor.VisitQuest(*this);
}

BGSBaseAlias* TESQuest::Function3d3220(const BSFixedString& name) const
{
    for (std::uint32_t index = 0; index < aliases.size; ++index) {
        auto* alias = aliases.data[index];
        if (alias && alias->aliasName._data == name._data) {
            return alias;
        }
    }
    return nullptr;
}

std::uint32_t& TESQuest::Function3d88c0(std::uint32_t& value)
{
    if (questInstanceValue == invalidQuestInstanceValue) {
        Function3d86b0();
    }
    value = questInstanceValue;
    return value;
}

BGSQuestInstanceText* TESQuest::Function3d8ac0(std::uint32_t id)
{
    BGSQuestInstanceText* found = nullptr;
    for (std::uint32_t index = 0; index < instanceData.size && !found; ++index) {
        auto* entry = instanceData.data[index];
        if (entry && entry->id == id) {
            found = entry;
        }
    }
    return found;
}

const BGSQuestInstanceText* TESQuest::Function3d8b10(std::uint32_t id) const
{
    const BGSQuestInstanceText* found = nullptr;
    for (std::uint32_t index = 0; index < instanceData.size && !found; ++index) {
        const auto* entry = instanceData.data[index];
        if (entry && entry->id == id) {
            found = entry;
        }
    }
    return found;
}
