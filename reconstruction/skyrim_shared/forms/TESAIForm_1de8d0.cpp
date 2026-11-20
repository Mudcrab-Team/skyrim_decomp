// Source exposure: mixed (pinned image listings, project form layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations from the listings and the cited community declarations.
// Adapted bodies: none
// 0x1de8d0 TESAIForm::ClearPackageList
// 0x1de940 TESAIForm::CopyPackageList
// 0x1de960 TESAIForm::GetAggressionLevel
// 0x1de970 TESAIForm::SetAggressionLevel
// 0x1de9a0 TESAIForm::GetAssistanceLevel
// 0x1dea10 TESAIForm::GetConfidenceSettingValue
// 0x1dead0 TESAIForm::GetConfidenceLevel
// 0x1deae0 TESAIForm::SetConfidenceLevel
// 0x1deb20 TESAIForm::GetEnergyLevel
// 0x1deb30 TESAIForm::SetEnergyLevel
// 0x1deb70 TESAIForm::SetMoralityLevel
// 0x1debb0 TESAIForm::GetMoodLevel
// 0x1debc0 TESAIForm::SetMoodLevel
// 0x1dede0 TESAIForm::AggroRadiusBehaviourIsEnabled
#include "TESAIForm_1de8d0.h"

// TESActorBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorBaseBeforeAI, earlierComponents: STANDIN GUESS(low)
class ActorBaseBeforeAI : public TESBoundAnimObject
{
    std::uint8_t earlierComponents[0x80];
};
static_assert(sizeof(ActorBaseBeforeAI) == 0xB0, "AI form base offset");

class TESActorBase : public ActorBaseBeforeAI, public TESAIForm {};

// kAIDataChange, skipPackageClear, ConfidenceSetting, confidenceSettings: STANDIN GUESS(low)
constexpr std::uint32_t kAIDataChange = 1u << 3;
extern const bool skipPackageClear;

struct ConfidenceSetting
{
    std::uint8_t padding[8];
    float value;
};
extern const ConfidenceSetting* const confidenceSettings[5];

void TESAIForm::ClearPackageList()
{
    if (!skipPackageClear) {
        aiPackages.Function4a2ce0();
    }
}

void TESAIForm::CopyPackageList(const TESAIForm& source)
{
    aiPackages.CopyFrom(source.aiPackages);
}

std::uint8_t TESAIForm::GetAggressionLevel() const
{
    return static_cast<std::uint8_t>(aiData.flags) & 3;
}

void TESAIForm::SetAggressionLevel(std::uint8_t value, bool notify)
{
    aiData.flags &= ~(3u << 0);
    aiData.flags |= (value & 3u) << 0;
    if (notify) {
        if (auto* actor = static_cast<TESActorBase*>(this)) {
            actor->AddChange(kAIDataChange);
        }
    }
}

std::uint8_t TESAIForm::GetAssistanceLevel() const
{
    return (aiData.flags >> 18) & 3;
}

float TESAIForm::GetConfidenceSettingValue(std::uint8_t level)
{
    if (level >= 5) {
        return 0.0f;
    }
    return confidenceSettings[level]->value;
}

std::uint8_t TESAIForm::GetConfidenceLevel() const
{
    return (aiData.flags >> 2) & 7;
}

void TESAIForm::SetConfidenceLevel(std::uint8_t value, bool notify)
{
    aiData.flags &= ~(7u << 2);
    aiData.flags |= (value & 7u) << 2;
    if (notify) {
        if (auto* actor = static_cast<TESActorBase*>(this)) {
            actor->AddChange(kAIDataChange);
        }
    }
}

std::uint8_t TESAIForm::GetEnergyLevel() const
{
    return (aiData.flags >> 5);
}

void TESAIForm::SetEnergyLevel(std::uint8_t value, bool notify)
{
    aiData.flags &= ~(255u << 5);
    aiData.flags |= std::uint32_t{value} << 5;
    if (notify) {
        if (auto* actor = static_cast<TESActorBase*>(this)) {
            actor->AddChange(kAIDataChange);
        }
    }
}

void TESAIForm::SetMoralityLevel(std::uint8_t value, bool notify)
{
    if (value < 4) {
        aiData.flags &= ~(3u << 13);
        aiData.flags |= (value & 3u) << 13;
        if (notify) {
            if (auto* actor = static_cast<TESActorBase*>(this)) {
                actor->AddChange(kAIDataChange);
            }
        }
    }
}

std::uint8_t TESAIForm::GetMoodLevel() const
{
    return (aiData.flags >> 15) & 7;
}

void TESAIForm::SetMoodLevel(std::uint8_t value)
{
    if (value < 8) {
        aiData.flags &= ~(7u << 15);
        aiData.flags |= (value & 7u) << 15;
        if (auto* actor = static_cast<TESActorBase*>(this)) {
            actor->AddChange(kAIDataChange);
        }
    }
}

bool TESAIForm::AggroRadiusBehaviourIsEnabled() const
{
    return (aiData.flags >> 20) & 1;
}
