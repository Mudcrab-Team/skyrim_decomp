// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x1df130 TESAttackDamageForm::GetAttackDamage
// 0x1df0c0 TESAttackDamageForm::InitializeDataComponent
// 0x1df1a0 TESAttackDamageForm::~TESAttackDamageForm
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
