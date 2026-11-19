// Source exposure: mixed (pinned image listings, project form layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial form declarations adapted from CommonLibSSE-NG.
// ClearPackageList, CopyPackageList: GUESS(low)
// GetAggressionLevel, GetAssistanceLevel, GetConfidenceLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetEnergyLevel, GetMoodLevel, AggroRadiusBehaviourIsEnabled, SetAggressionLevel, SetConfidenceLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetEnergyLevel, SetMoralityLevel, SetMoodLevel, GetConfidenceSettingValue: GUESS(low)
#pragma once

#include "TESBoundAnimObject.h"

// AIDATA_GAME, PackageList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flags, padding, Function4a2ce0, CopyFrom: STANDIN GUESS(low)
struct AIDATA_GAME
{
    std::uint32_t flags;
    std::uint8_t padding[8];
};
static_assert(sizeof(AIDATA_GAME) == 0xC, "AI data size");

struct PackageList
{
    void Function4a2ce0();
    void CopyFrom(const PackageList& source);

    std::uint64_t storage[2];
};

class TESAIForm : public BaseFormComponent
{
public:
    void ClearPackageList();
    void CopyPackageList(const TESAIForm& source);
    std::uint8_t GetAggressionLevel() const;
    void SetAggressionLevel(std::uint8_t value, bool notify);
    std::uint8_t GetAssistanceLevel() const;
    static float GetConfidenceSettingValue(std::uint8_t level);
    std::uint8_t GetConfidenceLevel() const;
    void SetConfidenceLevel(std::uint8_t value, bool notify);
    std::uint8_t GetEnergyLevel() const;
    void SetEnergyLevel(std::uint8_t value, bool notify);
    void SetMoralityLevel(std::uint8_t value, bool notify);
    std::uint8_t GetMoodLevel() const;
    void SetMoodLevel(std::uint8_t value);
    bool AggroRadiusBehaviourIsEnabled() const;

private:
    // aiData, aiPackages: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    AIDATA_GAME aiData;
    PackageList aiPackages;
};
