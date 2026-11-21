// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x27f830 TESObjectBOOK::InitializeData
// 0x280540 TESObjectBOOK::LoadGame
// 0x2804e0 TESObjectBOOK::SaveGame
// 0x280210 TESObjectBOOK::GetActivateText
// 0x27ff40 TESObjectBOOK::GetSpell
// Adapted bodies: none
#include "TESObjectBOOK.h"

// Not compared: defined so that the compiler emits the vftable (cookbook rule 14).
TESObjectBOOK::TESObjectBOOK()
{
}

// RVA 0x27f830, 28 bytes
void TESObjectBOOK::InitializeData()
{
    data = 0;
    teaches.spell = nullptr;
    inventoryModel = nullptr;
    TESForm::InitializeData();
}

// RVA 0x280540, 77 bytes
void TESObjectBOOK::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    LoadBaseSubobject(unk88, a_buf);
    if ((a_buf->changeFlags & 0x60) != 0) {
        a_buf->LoadDataEndian(&data, 1, 1);
    }
}

// RVA 0x2804e0, 85 bytes
void TESObjectBOOK::SaveGame(BGSSaveFormBuffer* a_buf)
{
    TESForm::SaveGame(a_buf);
    SaveBaseSubobject(unk88, a_buf);
    if ((a_buf->unk1B & 0x60) != 0) {
        a_buf->SaveDataEndian(&data, 1, 1, 0);
    }
}

// RVA 0x280210, 121 bytes
bool TESObjectBOOK::GetActivateText(TESObjectREFR* a_activator, BSString& a_dst)
{
    const char* verb;
    if ((data & 0x4) == 0 || teaches.spell == nullptr) {
        verb = g_activateVerbPlain;
    } else {
        verb = a_activator->IsCrimeToActivate() ? g_activateVerbSteal : g_activateVerbTake;
    }
    const char* displayName = a_activator->GetDisplayFullName();
    FormatString(a_dst, "%s\n%s", verb, displayName);
    return true;
}

SpellItem* TESObjectBOOK::GetSpell()
{
    if ((data & 0x4) != 0) {
        return teaches.spell;
    }
    return nullptr;
}
