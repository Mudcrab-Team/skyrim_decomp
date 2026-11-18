// Code origin: bodies written by the contributor from the compared functions' behaviour; names and
// declarations come from the header (CharmedBaryon/CommonLibSSE-NG, MIT).
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0x27f1b0 TESObjectARMO::GetDescriptionOwnerFile
// 0x27ef24 TESObjectARMO::dtor
// 0x27eef4 TESObjectARMO::dtor
// 0x27ef6c TESObjectARMO::dtor
// 0x27dae0 TESObjectARMO::InitializeData
// 0x27ee20 TESObjectARMO::SaveGame
// 0x27ee60 TESObjectARMO::LoadGame
#include "TESObjectARMO.h"

// ResolveOwnerFile: GUESS(low); address 0x1e5ae0 takes the form and a 32-bit file index (-1 for the
// latest owner) and returns the file; declared, not defined here.
TESFile* ResolveOwnerFile(const TESForm* a_form, std::uint32_t a_index);

// Defined so that the compiler emits the vftables of every base and, beside them, the deleting
// destructor and its adjustor thunks that are compared (cookbook rules 14 and 25).
TESObjectARMO::TESObjectARMO()
{
}

TESFile* TESObjectARMO::GetDescriptionOwnerFile() const
{
    return ResolveOwnerFile(templateArmor != nullptr ? templateArmor : this, 0xFFFFFFFFu);
}

void TESObjectARMO::InitializeData()
{
    armorRating = 0;
    templateArmor = nullptr;
    amountofEnchantment = 0;
}

void TESObjectARMO::SaveGame(BGSSaveFormBuffer* a_buf)
{
    TESForm::SaveGame(a_buf);
    TESValueForm::SaveGame(a_buf);
}

void TESObjectARMO::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    TESValueForm::LoadGame(a_buf);
}
