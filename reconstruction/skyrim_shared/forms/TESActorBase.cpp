// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: existing unit plus original reconstruction of GetIsPlayerOwner.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x3cc6d0 TESActorBase::GetHasPLSpecTex
// 0x3b03a0 TESActorBase::GetIsPlayerOwner
// 0x3cbc60 TESActorBase::~TESActorBase
// 0x3cc650 TESActorBase::GetCombatStyle
#include "TESActorBase.h"

TESActorBase::TESActorBase()
{
}

bool TESActorBase::GetIsPlayerOwner() const
{
    return formID == 7u;
}

TESCombatStyle* TESActorBase::GetCombatStyle()
{
    return nullptr;
}

bool TESActorBase::GetHasPLSpecTex() const
{
    return false;
}

void TESActorBase::RestoreActorValue(std::uint32_t a_modifier, std::uint32_t a_akValue, float a_value)
{
}
