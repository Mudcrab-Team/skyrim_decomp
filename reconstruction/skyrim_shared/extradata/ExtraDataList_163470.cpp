/*
 * ExtraDataList: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x163470 33 bytes; RVA 0x164390 33 bytes; RVA 0x1645d0 33 bytes; RVA 0x164790 33 bytes; RVA 0x164980 33 bytes; RVA 0x164c20 33 bytes; RVA 0x164c50 33 bytes; RVA 0x164cc0 33 bytes; RVA 0x164d50 33 bytes; RVA 0x164d80 33 bytes; RVA 0x164df0 33 bytes; RVA 0x165e20 33 bytes; RVA 0x166af0 33 bytes; RVA 0x166cf0 33 bytes; RVA 0x166e40 33 bytes; RVA 0x166f90 33 bytes; RVA 0x168070 33 bytes; RVA 0x168b00 33 bytes; RVA 0x169670 33 bytes; RVA 0x1696a0 33 bytes; RVA 0x169a60 33 bytes; RVA 0x169dc0 33 bytes; RVA 0x16e590 33 bytes; RVA 0x16f540 33 bytes; RVA 0x16f690 33 bytes; RVA 0x16f7e0 33 bytes; RVA 0x16f930 33 bytes; RVA 0x16fa80 33 bytes; RVA 0x16fbd0 33 bytes; RVA 0x1704d0 33 bytes; RVA 0x1708d0 33 bytes; RVA 0x170c20 33 bytes; RVA 0x172690 33 bytes; RVA 0x1732e0 33 bytes; RVA 0x173310 33 bytes.
 * Origin: original reconstruction.
 * Source exposure: mixed (binary-analysis and community-headers).
 * Drafted by: gpt-6.1-terra.
 * Two field accessors repaired by: gpt-6.1-sol.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Names informed by CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT). Stand-ins are unverified.
 */
// ExtraDataList: GUESS(low) STANDIN
#include "ExtraDataList_163470.h"

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

TESGlobal* ExtraDataList::Function1645d0() {
    auto extra = static_cast<ExtraGlobal*>(LookupExtra(0x22));
    return extra ? extra->global : nullptr;
}

InventoryChanges* ExtraDataList::GetInventoryChanges() {
    auto extra = static_cast<ExtraContainerChanges*>(LookupExtra(0x15));
    return extra ? extra->changes : nullptr;
}

TESPackage* ExtraDataList::GetPackage() {
    auto extra = static_cast<ExtraPackage*>(LookupExtra(0x19));
    return extra ? extra->unk10 : nullptr;
}

TrespassPackage* ExtraDataList::Function164d50() {
    auto extra = static_cast<ExtraTresPassPackage*>(LookupExtra(0x1a));
    return extra ? extra->pack : nullptr;
}

BSSimpleList<Crime*>* ExtraDataList::Function164df0() {
    auto extra = static_cast<ExtraPlayerCrimeList*>(LookupExtra(0x34));
    return extra ? extra->crimes : nullptr;
}

BGSDecalGroup* ExtraDataList::Function166af0() {
    auto extra = static_cast<ExtraDecalGroup*>(LookupExtra(0xa2));
    return extra ? extra->decalGroup : nullptr;
}

BGSLocationRefType* ExtraDataList::Function166cf0() {
    auto extra = static_cast<ExtraLocationRefType*>(LookupExtra(0x8b));
    return extra ? extra->locRefType : nullptr;
}

TESObjectREFR* ExtraDataList::Function166e40() {
    auto extra = static_cast<ExtraRandomTeleportMarker*>(LookupExtra(0x3a));
    return extra ? extra->marker : nullptr;
}

TESLevItem* ExtraDataList::Function166f90() {
    auto extra = static_cast<ExtraLeveledItemBase*>(LookupExtra(0x90));
    return extra ? extra->levItem : nullptr;
}

TESActorBase* ExtraDataList::GetLeveledNPC() {
    auto extra = static_cast<ExtraLeveledCreature*>(LookupExtra(0x2d));
    return extra ? extra->originalBase : nullptr;
}

BGSScene* ExtraDataList::Function169a60() {
    auto extra = static_cast<ExtraSceneData*>(LookupExtra(0x92));
    return extra ? extra->scene : nullptr;
}

SeenData* ExtraDataList::Function16e590() {
    auto extra = static_cast<ExtraSeenData*>(LookupExtra(0x5));
    return extra ? extra->seenData : nullptr;
}

TESRegionList* ExtraDataList::Function16f540() {
    auto extra = static_cast<ExtraRegionList*>(LookupExtra(0x4));
    if (!extra) return nullptr;
    return extra->list;
}

BGSMusicType* ExtraDataList::Function16f690() {
    auto extra = static_cast<ExtraCellMusicType*>(LookupExtra(0x7));
    if (!extra) return nullptr;
    return extra->type;
}

BGSAcousticSpace* ExtraDataList::Function16f7e0() {
    auto extra = static_cast<ExtraCellAcousticSpace*>(LookupExtra(0x7d));
    if (!extra) return nullptr;
    return extra->space;
}

TESRegion* ExtraDataList::Function16f930() {
    auto extra = static_cast<ExtraCellSkyRegion*>(LookupExtra(0x8));
    return extra ? extra->skyRegion : nullptr;
}

TESImageSpace* ExtraDataList::Function16fa80() {
    auto extra = static_cast<ExtraCellImageSpace*>(LookupExtra(0x56));
    if (!extra) return nullptr;
    return extra->imageSpace;
}

TESModel* ExtraDataList::Function16fbd0() {
    auto extra = static_cast<ExtraModelSwap*>(LookupExtra(0x58));
    return extra ? extra->modelSwap : nullptr;
}

TESForm* ExtraDataList::Function1708d0() {
    auto extra = static_cast<ExtraStartingWorldOrCell*>(LookupExtra(0x48));
    return extra ? extra->startingWorldOrCell : nullptr;
}

bool ExtraDataList::IsGhost() {
    auto extra = static_cast<ExtraGhost*>(LookupExtra(0x1f));
    return extra ? extra->ghost : 0;
}

std::uint16_t ExtraDataList::GetMaximumCharge() {
    auto extra = static_cast<ExtraEnchantment*>(LookupExtra(0x9b));
    return extra ? extra->charge : 0;
}

bool ExtraDataList::Function173310() {
    auto extra = static_cast<ExtraEnchantment*>(LookupExtra(0x9b));
    return extra ? extra->removeOnUnequip : 0;
}

FILE_POS_ROT* ExtraDataList::Function164390() {
    auto extra = static_cast<ExtraStartingPosition*>(LookupExtra(0xe));
    return extra ? &extra->startPosition : nullptr;
}

WORLD_LOCATION* ExtraDataList::Function164c50() {
    auto extra = static_cast<ExtraPackageStartLocation*>(LookupExtra(0x18));
    if (!extra) return nullptr;
    return &extra->worldLoc;
}

BSSimpleList<REF_ACTIVATE_DATA*>* ExtraDataList::Function168070() {
    auto extra = static_cast<ExtraActivateRef*>(LookupExtra(0x52));
    return extra ? &extra->parents : nullptr;
}

BSSimpleList<REF_ACTIVATE_DATA*>* ExtraDataList::Function168b00() {
    auto extra = static_cast<ExtraActivateRefChildren*>(LookupExtra(0x53));
    return extra ? &extra->children : nullptr;
}

REFR_LIGHT* ExtraDataList::Function169dc0() {
    auto extra = static_cast<ExtraMagicLight*>(LookupExtra(0x3f));
    return extra ? extra->lightData : nullptr;
}

std::int32_t ExtraDataList::GetSoulLevel() {
    auto extra = static_cast<ExtraSoul*>(LookupExtra(0x9c));
    return extra ? extra->soul : 0;
}

std::uint8_t ExtraDataList::Function172690() {
    auto extra = static_cast<ExtraAlphaCutoff*>(LookupExtra(0x9a));
    return extra ? static_cast<std::uint8_t>(extra->cutoff) : 0;
}

TESActorBase* ExtraDataList::Function1696a0() {
    auto extra = static_cast<ExtraLeveledCreature*>(LookupExtra(0x2d));
    return extra ? extra->templateBase : nullptr;
}

TESObjectREFR* ExtraDataList::Function170c20() {
    auto extra = static_cast<ExtraAction*>(LookupExtra(0xd));
    if (!extra) return nullptr;
    return extra->actionRef;
}

const char* ExtraDataList::Function1704d0() {
    auto extra = static_cast<ExtraEditorID*>(LookupExtra(0x6));
    if (!extra) return nullptr;
    return extra->editorID.data;
}

BSSimpleList<ObjectRefHandle>* ExtraDataList::Function165e20() {
    auto extra = static_cast<ExtraAttachRefChildren*>(LookupExtra(0xad));
    return extra ? &extra->children : nullptr;
}

std::int32_t ExtraDataList::Function164d80() {
    auto extra = static_cast<ExtraPackage*>(LookupExtra(0x19));
    return extra ? extra->value1C : 0;
}

std::uint8_t ExtraDataList::Function163470() {
    auto extra = static_cast<ExtraTerminalState*>(LookupExtra(0x4f));
    if (!extra) return 0;
    return extra->state;
}
