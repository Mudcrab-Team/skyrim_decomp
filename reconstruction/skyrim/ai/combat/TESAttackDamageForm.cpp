// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
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
