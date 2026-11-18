/*
 * ExtraDataList: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x163470 33 bytes; RVA 0x164390 33 bytes; RVA 0x1645d0 33 bytes; RVA 0x164790 33 bytes; RVA 0x164980 33 bytes; RVA 0x164c20 33 bytes; RVA 0x164c50 33 bytes; RVA 0x164cc0 33 bytes; RVA 0x164d50 33 bytes; RVA 0x164d80 33 bytes; RVA 0x164df0 33 bytes; RVA 0x165e20 33 bytes; RVA 0x166af0 33 bytes; RVA 0x166cf0 33 bytes; RVA 0x166e40 33 bytes; RVA 0x166f90 33 bytes; RVA 0x168070 33 bytes; RVA 0x168b00 33 bytes; RVA 0x169670 33 bytes; RVA 0x1696a0 33 bytes; RVA 0x169a60 33 bytes; RVA 0x169dc0 33 bytes; RVA 0x16e590 33 bytes; RVA 0x16f540 33 bytes; RVA 0x16f690 33 bytes; RVA 0x16f7e0 33 bytes; RVA 0x16f930 33 bytes; RVA 0x16fa80 33 bytes; RVA 0x16fbd0 33 bytes; RVA 0x1704d0 33 bytes; RVA 0x1708d0 33 bytes; RVA 0x170c20 33 bytes; RVA 0x172690 33 bytes; RVA 0x1732e0 33 bytes; RVA 0x173310 33 bytes.
 * Origin: original reconstruction.
 * Source exposure: mixed (binary-analysis and community-headers).
 * Drafted by: gpt-6.1-terra.
 * Partial field hypotheses repaired by: gpt-6.1-sol.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Partial declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT). Stand-ins are unverified.
 */
// ExtraDataList: GUESS(low) STANDIN
#pragma once

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

#include <cstdint>
// BSExtraData, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
// BGSAcousticSpace: GUESS(low) STANDIN
class BGSAcousticSpace;
// BGSDecalGroup: GUESS(low) STANDIN
class BGSDecalGroup;
// BGSLocationRefType: GUESS(low) STANDIN
class BGSLocationRefType;
// BGSMusicType: GUESS(low) STANDIN
class BGSMusicType;
// BGSScene: GUESS(low) STANDIN
class BGSScene;
// Crime, BSSimpleList: GUESS(low) STANDIN
class Crime;
template<class T> class BSSimpleList;
// InventoryChanges: GUESS(low) STANDIN
class InventoryChanges;
// SeenData: GUESS(low) STANDIN
class SeenData;
// TESActorBase: GUESS(low) STANDIN
class TESActorBase;
// TESForm: GUESS(low) STANDIN
class TESForm;
// TESGlobal: GUESS(low) STANDIN
class TESGlobal;
// TESImageSpace: GUESS(low) STANDIN
class TESImageSpace;
// TESLevItem: GUESS(low) STANDIN
class TESLevItem;
// TESModel: GUESS(low) STANDIN
class TESModel;
// TESObjectREFR: GUESS(low) STANDIN
class TESObjectREFR;
// TESPackage: GUESS(low) STANDIN
class TESPackage;
// TESRegion: GUESS(low) STANDIN
class TESRegion;
// TESRegionList: GUESS(low) STANDIN
class TESRegionList;
// TrespassPackage: GUESS(low) STANDIN
class TrespassPackage;
// ExtraGlobal, global: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraGlobal : public BSExtraData { public: TESGlobal* global; };
// ExtraContainerChanges, changes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraContainerChanges : public BSExtraData { public: InventoryChanges* changes; };
// ObjectRefHandle, value: GUESS(low) STANDIN
struct ObjectRefHandle { std::uint32_t value; };
// ExtraPackage, unk10, index: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
// value1C: GUESS(low); Partial signed field inferred from this accessor; the community handle declaration differs.
class ExtraPackage : public BSExtraData { public: TESPackage* unk10; std::int32_t index; std::int16_t value1C; };
// ExtraTresPassPackage, pack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraTresPassPackage : public BSExtraData { public: TrespassPackage* pack; };
// ExtraPlayerCrimeList, crimes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraPlayerCrimeList : public BSExtraData { public: BSSimpleList<Crime*>* crimes; };
// ExtraDecalGroup, decalGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraDecalGroup : public BSExtraData { public: BGSDecalGroup* decalGroup; };
// ExtraLocationRefType, locRefType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraLocationRefType : public BSExtraData { public: BGSLocationRefType* locRefType; };
// ExtraRandomTeleportMarker, marker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraRandomTeleportMarker : public BSExtraData { public: TESObjectREFR* marker; };
// ExtraLeveledItemBase, levItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraLeveledItemBase : public BSExtraData { public: TESLevItem* levItem; };
// ExtraLeveledCreature, originalBase, templateBase: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraLeveledCreature : public BSExtraData { public: TESActorBase* originalBase; TESActorBase* templateBase; };
// ExtraSceneData, scene: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraSceneData : public BSExtraData { public: BGSScene* scene; };
// ExtraSeenData, seenData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraSeenData : public BSExtraData { public: SeenData* seenData; };
// ExtraRegionList, list: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraRegionList : public BSExtraData { public: TESRegionList* list; };
// ExtraCellMusicType, type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraCellMusicType : public BSExtraData { public: BGSMusicType* type; };
// ExtraCellAcousticSpace, space: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraCellAcousticSpace : public BSExtraData { public: BGSAcousticSpace* space; };
// ExtraCellSkyRegion, skyRegion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraCellSkyRegion : public BSExtraData { public: TESRegion* skyRegion; };
// ExtraCellImageSpace, imageSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraCellImageSpace : public BSExtraData { public: TESImageSpace* imageSpace; };
// ExtraModelSwap, modelSwap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraModelSwap : public BSExtraData { public: TESModel* modelSwap; };
// ExtraStartingWorldOrCell, startingWorldOrCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraStartingWorldOrCell : public BSExtraData { public: TESForm* startingWorldOrCell; };
// ExtraGhost, ghost: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraGhost : public BSExtraData { public: bool ghost; };
// ExtraEnchantment, enchantment, charge, removeOnUnequip: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class EnchantmentItem;
class ExtraEnchantment : public BSExtraData { public: EnchantmentItem* enchantment; std::uint16_t charge; bool removeOnUnequip; };
// NiPoint3, x, y, z, FILE_POS_ROT, pos, rot, WORLD_LOCATION, locationForm, locPt, zRot: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
struct NiPoint3 { float x, y, z; };
struct FILE_POS_ROT { NiPoint3 pos, rot; };
struct WORLD_LOCATION { TESForm* locationForm; NiPoint3 locPt; float zRot; };
// ExtraStartingPosition, startPosition, ExtraPackageStartLocation, worldLoc: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraStartingPosition : public BSExtraData { public: FILE_POS_ROT startPosition; };
class ExtraPackageStartLocation : public BSExtraData { public: WORLD_LOCATION worldLoc; };
// REF_ACTIVATE_DATA, BSSimpleList, Node, item, next, _listHead: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class REF_ACTIVATE_DATA;
template<class T> class BSSimpleList { public: struct Node { T item; Node* next; }; Node _listHead; };
// ExtraActivateRef, parents, ExtraActivateRefChildren, children: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraActivateRef : public BSExtraData { public: BSSimpleList<REF_ACTIVATE_DATA*> parents; };
class ExtraActivateRefChildren : public BSExtraData { public: BSSimpleList<REF_ACTIVATE_DATA*> children; };
// REFR_LIGHT, ExtraLight, lightData, ExtraMagicLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class REFR_LIGHT;
class ExtraLight : public BSExtraData { public: REFR_LIGHT* lightData; };
class ExtraMagicLight : public ExtraLight {};
// ExtraSoul, ExtraAlphaCutoff, cutoff: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
// soul: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) GUESS(low)
class ExtraSoul : public BSExtraData { public: std::int8_t soul; };
class ExtraAlphaCutoff : public BSExtraData { public: std::int8_t cutoff; };
// ExtraAction, action, actionRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraAction : public BSExtraData { public: std::int8_t action; TESObjectREFR* actionRef; };
// BSFixedString, data, ExtraEditorID, editorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class BSFixedString { public: const char* data; };
class ExtraEditorID : public BSExtraData { public: BSFixedString editorID; };
// ExtraAttachRefChildren, children: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class ExtraAttachRefChildren : public BSExtraData { public: BSSimpleList<ObjectRefHandle> children; };
// ExtraTerminalState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
// state: GUESS(low); Partial byte field inferred from this accessor; complete layout and meaning remain unknown.
class ExtraTerminalState : public BSExtraData { public: std::uint8_t state; };
// ExtraDataList: GUESS(low) STANDIN
class ExtraDataList { public:
// Function163470: GUESS(low)
std::uint8_t Function163470();
// Function164d80: GUESS(low)
std::int32_t Function164d80();
// Function165e20: GUESS(low)
BSSimpleList<ObjectRefHandle>* Function165e20();
// Function1704d0: GUESS(low)
const char* Function1704d0();
// Function170c20: GUESS(low)
TESObjectREFR* Function170c20();
// Function1696a0: GUESS(low)
TESActorBase* Function1696a0();
// Function172690: GUESS(low)
std::uint8_t Function172690();
// GetSoulLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) GUESS(low)
std::int32_t GetSoulLevel();
// Function169dc0: GUESS(low)
REFR_LIGHT* Function169dc0();
// Function168b00: GUESS(low)
BSSimpleList<REF_ACTIVATE_DATA*>* Function168b00();
// Function168070: GUESS(low)
BSSimpleList<REF_ACTIVATE_DATA*>* Function168070();
// Function164c50: GUESS(low)
WORLD_LOCATION* Function164c50();
// Function164390: GUESS(low)
FILE_POS_ROT* Function164390();
// LookupExtra: GUESS(low)
BSExtraData* LookupExtra(unsigned int);
// Function1645d0: GUESS(low)
TESGlobal* Function1645d0();
// GetInventoryChanges: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) GUESS(low)
InventoryChanges* GetInventoryChanges();
// GetPackage: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) GUESS(low)
TESPackage* GetPackage();
// Function164d50: GUESS(low)
TrespassPackage* Function164d50();
// Function164df0: GUESS(low)
BSSimpleList<Crime*>* Function164df0();
// Function166af0: GUESS(low)
BGSDecalGroup* Function166af0();
// Function166cf0: GUESS(low)
BGSLocationRefType* Function166cf0();
// Function166e40: GUESS(low)
TESObjectREFR* Function166e40();
// Function166f90: GUESS(low)
TESLevItem* Function166f90();
// GetLeveledNPC: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) GUESS(low)
TESActorBase* GetLeveledNPC();
// Function169a60: GUESS(low)
BGSScene* Function169a60();
// Function16e590: GUESS(low)
SeenData* Function16e590();
// Function16f540: GUESS(low)
TESRegionList* Function16f540();
// Function16f690: GUESS(low)
BGSMusicType* Function16f690();
// Function16f7e0: GUESS(low)
BGSAcousticSpace* Function16f7e0();
// Function16f930: GUESS(low)
TESRegion* Function16f930();
// Function16fa80: GUESS(low)
TESImageSpace* Function16fa80();
// Function16fbd0: GUESS(low)
TESModel* Function16fbd0();
// Function1708d0: GUESS(low)
TESForm* Function1708d0();
// IsGhost: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) GUESS(low)
bool IsGhost();
// GetMaximumCharge: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) GUESS(low)
std::uint16_t GetMaximumCharge();
// Function173310: GUESS(low)
bool Function173310();
};
