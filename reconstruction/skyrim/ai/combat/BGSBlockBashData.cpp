// Source exposure: mixed. Drafted from the local instruction listings of the pinned image, with the class
// layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x1d2240 BGSBlockBashData::InitializeDataComponent
// 0x1d2390 GetBlockBashData
#include "BGSBlockBashData.h"

BGSBlockBashData::BGSBlockBashData()
{
}

void BGSBlockBashData::ClearDataComponent()
{
}

void BGSBlockBashData::InitializeDataComponent()
{
    blockBashImpactDataSet = nullptr;
    altBlockMaterialType = nullptr;
}

BGSBlockBashData* GetBlockBashData(TESForm* a_form)
{
    if (a_form) {
        switch (a_form->formType) {
        case TESForm::kArmor:
            return &static_cast<TESObjectARMO*>(a_form)->blockBashData;
        case TESForm::kWeapon:
            return &static_cast<TESObjectWEAP*>(a_form)->blockBashData;
        }
    }
    return nullptr;
}
