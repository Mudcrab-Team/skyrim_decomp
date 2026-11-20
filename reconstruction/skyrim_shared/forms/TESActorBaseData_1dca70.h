// Source exposure: mixed (pinned image listings, project form layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial form declarations adapted from CommonLibSSE-NG.
// templateState: STANDIN GUESS(low)
// HasCopiedTemplate, SetCopiedTemplate, GetBaseTemplateForm: GUESS(low)
// HasLeveledBaseTemplate, Function1dcb80, ResolveTemplateForm, SetActorBaseFlags: GUESS(low)
// SetMagickaOffset, SetStaminaOffset: GUESS(low)
// SetHealthOffset, SetSpeedMult, AddTemplateState, RemoveTemplateState: GUESS(low)
#pragma once

#include "TESBoundAnimObject.h"

// ACTOR_BASE_DATA, actorBaseFlags, magickaOffset, staminaOffset, level: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// calcLevelMin, calcLevelMax, speedMult, baseDisposition, templateUseFlags, healthOffset: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct ACTOR_BASE_DATA
{
    std::uint32_t actorBaseFlags;
    std::int16_t magickaOffset;
    std::int16_t staminaOffset;
    std::uint16_t level;
    std::uint16_t calcLevelMin;
    std::uint16_t calcLevelMax;
    std::uint16_t speedMult;
    std::uint16_t baseDisposition;
    std::uint16_t templateUseFlags;
    std::int16_t healthOffset;
    std::int16_t bleedoutOverride;
};
static_assert(sizeof(ACTOR_BASE_DATA) == 0x18, "actor data size");


class TESActorBaseData : public BaseFormComponent
{
public:
    bool HasCopiedTemplate() const;
    void SetCopiedTemplate(bool copied);
    TESForm* GetBaseTemplateForm() const;
    bool HasLeveledBaseTemplate() const;
    bool Function1dcb80() const;
    void SetActorBaseFlags(std::uint32_t value);
    void SetMagickaOffset(std::int16_t value);
    void SetStaminaOffset(std::int16_t value);
    void SetHealthOffset(std::int16_t value);
    void SetSpeedMult(std::uint16_t value);
    void AddTemplateState(std::uint32_t flags);
    void RemoveTemplateState(std::uint32_t flags);


private:
    // actorData, baseTemplateForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ACTOR_BASE_DATA actorData;
    std::uint8_t padding20[0x10];
    TESForm* baseTemplateForm;
    std::uint32_t templateState;
};
