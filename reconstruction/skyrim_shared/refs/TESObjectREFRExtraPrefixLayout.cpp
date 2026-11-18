// Source exposure: mixed (pinned target image, community headers).
// Code origin: target-informed original member-delegation bodies; GetLinkedRef follows the trivial delegation in CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/T/TESObjectREFR.cpp (MIT). No sibling body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Prefix layout names and inferred members: GUESS(low) STANDIN
// Community type and member names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2dfbc0 Extra-data member forwarding wrapper
// 0x2e6a90 Extra-data member forwarding wrapper
// 0x2e6aa0 Extra-data member forwarding wrapper
// 0x2e76f0 Extra-data member forwarding wrapper
// 0x2e7a10 Extra-data member forwarding wrapper
// 0x2e7a20 Extra-data member forwarding wrapper
// 0x2e7b50 Extra-data member forwarding wrapper
// 0x300730 Extra-data member forwarding wrapper
// 0x301120 Extra-data member forwarding wrapper
// 0x301410 Extra-data member forwarding wrapper
// 0x301da0 Extra-data member forwarding wrapper
// 0x301f50 Extra-data member forwarding wrapper
// 0x301ff0 Extra-data member forwarding wrapper
// 0x302030 Extra-data member forwarding wrapper
// 0x302ff0 Extra-data member forwarding wrapper
// 0x3033d0 Extra-data member forwarding wrapper
// 0x302050 Extra-data member forwarding wrapper
#include "TESObjectREFRExtraPrefixLayout.h"
namespace ResearchLayouts {
void TESObjectREFRExtraPrefixLayout::ForceEditorLocation(BGSLocation* location) { extraList.ForceEditorLocation(location); }
BGSScene* TESObjectREFRExtraPrefixLayout::GetCurrentScene() const { return extraList.GetCurrentScene(); }
void TESObjectREFRExtraPrefixLayout::SetCurrentScene(BGSScene* scene) { extraList.SetCurrentScene(scene); }
REFR_LIGHT* TESObjectREFRExtraPrefixLayout::GetMagicLightData() const { return extraList.GetMagicLightData(); }
OBJECT_ACTION TESObjectREFRExtraPrefixLayout::GetAction() const { return extraList.GetAction(); }
bool TESObjectREFRExtraPrefixLayout::HasAction(unsigned int flags) const { return extraList.HasAction(flags); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetActionReference() const { return extraList.GetActionReference(); }
TESForm* TESObjectREFRExtraPrefixLayout::GetOwner() const { return const_cast<ExtraDataList&>(extraList).GetOwner(); }
MapMarkerData* TESObjectREFRExtraPrefixLayout::GetMapMarkerData() const { return extraList.GetMapMarkerData(); }
REFR_LOCK* TESObjectREFRExtraPrefixLayout::GetLock() const { return extraList.GetLock(); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetMultiBoundRef() const { return extraList.GetMultiBoundRef(); }
BGSLocationRefType* TESObjectREFRExtraPrefixLayout::GetLocationRefType() const { return extraList.GetLocationRefType(); }
TESForm* TESObjectREFRExtraPrefixLayout::GetEmittanceSource() const { return extraList.GetEmittanceSource(); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetRandomTeleportMarker() const { return extraList.GetRandomTeleportMarker(); }
bool TESObjectREFRExtraPrefixLayout::IsOppositeEnableState() const { return extraList.IsOppositeEnableState(); }
EnableStateChildren* TESObjectREFRExtraPrefixLayout::GetEnableStateChildren() const { return extraList.GetEnableStateChildren(); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetLinkedRef(BGSKeyword* keyword) { return extraList.GetLinkedRef(keyword); }
}
