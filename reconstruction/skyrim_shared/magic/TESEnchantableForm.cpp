// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x1e20d0 TESEnchantableForm::GetCastingType
// 0x1e1e60 TESEnchantableForm::InitializeDataComponent
// 0x1e20a0 TESEnchantableForm::~TESEnchantableForm
#include "TESEnchantableForm.h"

TESEnchantableForm::TESEnchantableForm()
{
}

TESEnchantableForm::~TESEnchantableForm()
{
}

std::uint16_t TESEnchantableForm::GetCastingType() const
{
    return castingType;
}

void TESEnchantableForm::InitializeDataComponent()
{
    castingType = 3;
    amountofEnchantment = 0;
    formEnchanting = nullptr;
}

void TESEnchantableForm::ClearDataComponent()
{
}
