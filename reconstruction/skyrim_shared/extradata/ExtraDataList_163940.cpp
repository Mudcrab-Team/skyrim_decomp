// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG include/RE/E/ExtraDataList.h, ExtraDataTypes.h, and individual extra data headers, and include/RE/B/BSExtraData.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList, GetByType, GetOwner, BSExtraData, next, ExtraDataType, ExtraDetachTime, time, ExtraPoison, poison, count, ExtraLight, lightData, ExtraLock, lock, ExtraTeleport, teleportData, ExtraMapMarker, mapData, ExtraOwnership, owner, ExtraLockList, list: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HasHotkey, QueryDetachTime, GetPoisonCount, GetLightData, GetMapMarkerData, QueryLockList: GUESS(low)
// GetLockData, GetTeleportData: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// REFR_LIGHT, REFR_LOCK, DoorTeleportData, MapMarkerData, TESForm, AlchemyItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x163940 ExtraDataList::HasHotkey
// 0x1697f0 ExtraDataList::QueryDetachTime
// 0x169d90 ExtraDataList::GetPoisonCount
// 0x164450 ExtraDataList::GetLightData
// 0x164480 ExtraDataList::GetLockData
// 0x1644b0 ExtraDataList::GetTeleportData
// 0x1644e0 ExtraDataList::GetMapMarkerData
// 0x164570 ExtraDataList::GetOwner
// 0x1645a0 ExtraDataList::QueryLockList
#include "ExtraDataList_163940.h"
bool ExtraDataList::HasHotkey() { return GetByType(ExtraDataType::kHotkey) != nullptr; }
std::uint32_t ExtraDataList::QueryDetachTime() { auto* data = static_cast<ExtraDetachTime*>(GetByType(ExtraDataType::kDetachTime)); return data ? data->time : 0; }
std::uint32_t ExtraDataList::GetPoisonCount() { auto* data = static_cast<ExtraPoison*>(GetByType(ExtraDataType::kPoison)); return data ? data->count : 0; }
REFR_LIGHT* ExtraDataList::GetLightData() { auto* data = static_cast<ExtraLight*>(GetByType(ExtraDataType::kLight)); return data ? data->lightData : nullptr; }
REFR_LOCK* ExtraDataList::GetLockData() { auto* data = static_cast<ExtraLock*>(GetByType(ExtraDataType::kLock)); return data ? data->lock : nullptr; }
DoorTeleportData* ExtraDataList::GetTeleportData() { auto* data = static_cast<ExtraTeleport*>(GetByType(ExtraDataType::kTeleport)); return data ? data->teleportData : nullptr; }
MapMarkerData* ExtraDataList::GetMapMarkerData() { auto* data = static_cast<ExtraMapMarker*>(GetByType(ExtraDataType::kMapMarker)); return data ? data->mapData : nullptr; }
TESForm* ExtraDataList::GetOwner() { auto* data = static_cast<ExtraOwnership*>(GetByType(ExtraDataType::kOwnership)); return data ? data->owner : nullptr; }
TESForm* ExtraDataList::QueryLockList() { auto* data = static_cast<ExtraLockList*>(GetByType(ExtraDataType::kLockList)); return data ? data->list : nullptr; }
