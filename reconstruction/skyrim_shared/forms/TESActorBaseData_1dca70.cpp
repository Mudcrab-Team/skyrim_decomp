// Source exposure: mixed (pinned image listings, project form layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations from the listings and the cited community declarations.
// Adapted bodies: none
// 0x1dca70 TESActorBaseData::HasCopiedTemplate
// 0x1dca80 TESActorBaseData::SetCopiedTemplate
// 0x1dcb20 TESActorBaseData::GetBaseTemplateForm
// 0x1dcb60 TESActorBaseData::HasLeveledBaseTemplate
// 0x1dcb80 TESActorBaseData::Function1dcb80
// 0x1dd2a0 TESActorBaseData::SetActorBaseFlags
// 0x1dd4b0 TESActorBaseData::SetMagickaOffset
// 0x1dd4d0 TESActorBaseData::SetStaminaOffset
// 0x1dd4f0 TESActorBaseData::SetHealthOffset
// 0x1dd960 TESActorBaseData::SetSpeedMult
// 0x1dd9f0 TESActorBaseData::AddTemplateState
// 0x1dda00 TESActorBaseData::RemoveTemplateState
#include "TESActorBaseData_1dca70.h"

// TESActorBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESActorBase : public TESBoundAnimObject, public TESActorBaseData {};

static_assert(sizeof(TESBoundAnimObject) == 0x30, "actor data base offset");

// kBaseDataChange, kLeveledNPC: STANDIN GUESS(low)
constexpr FormType kLeveledNPC = static_cast<FormType>(0x2C);
constexpr std::uint32_t kBaseDataChange = 1u << 1;

bool TESActorBaseData::HasCopiedTemplate() const
{
    return actorData.templateUseFlags >> 15;
}

void TESActorBaseData::SetCopiedTemplate(bool copied)
{
    if (copied) {
        actorData.templateUseFlags |= 1u << 15;
    } else {
        actorData.templateUseFlags &= ~(1u << 15);
    }
}

TESForm* TESActorBaseData::GetBaseTemplateForm() const
{
    return baseTemplateForm;
}

bool TESActorBaseData::HasLeveledBaseTemplate() const
{
    return baseTemplateForm && baseTemplateForm->formType == kLeveledNPC;
}

bool TESActorBaseData::Function1dcb80() const
{
    return baseTemplateForm && baseTemplateForm->formType == kLeveledNPC;
}

void TESActorBaseData::SetActorBaseFlags(std::uint32_t value)
{
    actorData.actorBaseFlags = value;
    if (auto* actor = static_cast<TESActorBase*>(this)) {
        actor->AddChange(kBaseDataChange);
    }
}

void TESActorBaseData::SetMagickaOffset(std::int16_t value)
{
    actorData.magickaOffset = value;
    if (auto* actor = static_cast<TESActorBase*>(this)) {
        actor->AddChange(kBaseDataChange);
    }
}

void TESActorBaseData::SetStaminaOffset(std::int16_t value)
{
    actorData.staminaOffset = value;
    if (auto* actor = static_cast<TESActorBase*>(this)) {
        actor->AddChange(kBaseDataChange);
    }
}

void TESActorBaseData::SetHealthOffset(std::int16_t value)
{
    actorData.healthOffset = value;
    if (auto* actor = static_cast<TESActorBase*>(this)) {
        actor->AddChange(kBaseDataChange);
    }
}

void TESActorBaseData::SetSpeedMult(std::uint16_t value)
{
    actorData.speedMult = value;
    if (auto* actor = static_cast<TESActorBase*>(this)) {
        actor->AddChange(kBaseDataChange);
    }
}

void TESActorBaseData::AddTemplateState(std::uint32_t flags)
{
    templateState |= flags;
}

void TESActorBaseData::RemoveTemplateState(std::uint32_t flags)
{
    templateState &= ~flags;
}
