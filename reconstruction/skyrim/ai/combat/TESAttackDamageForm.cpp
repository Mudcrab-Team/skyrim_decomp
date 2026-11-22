// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x1df190 TESAttackDamageForm::Function1df190
// Adapted bodies: none
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
#include "TESAttackDamageForm.h"

TESAttackDamageForm::TESAttackDamageForm()
{
}

TESAttackDamageForm::~TESAttackDamageForm()
{
}

std::uint16_t TESAttackDamageForm::GetAttackDamage() const
{
    return attackDamage;
}

void TESAttackDamageForm::ClearDataComponent()
{
}

void TESAttackDamageForm::InitializeDataComponent()
{
    attackDamage = 0;
}

void TESAttackDamageForm::Function1df190(std::uint16_t a_value)
{
    attackDamage = a_value;
}
