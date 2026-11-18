// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG include/RE/E/ExtraDataList.h, ExtraDataTypes.h, and individual extra data headers, and include/RE/B/BSExtraData.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList, GetByType, GetOwner, BSExtraData, next, ExtraDataType, ExtraDetachTime, time, ExtraPoison, poison, count, ExtraLight, lightData, ExtraLock, lock, ExtraTeleport, teleportData, ExtraMapMarker, mapData, ExtraOwnership, owner, ExtraLockList, list: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HasHotkey, QueryDetachTime, GetPoisonCount, GetLightData, GetMapMarkerData, QueryLockList: GUESS(low)
// GetLockData, GetTeleportData: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// REFR_LIGHT, REFR_LOCK, DoorTeleportData, MapMarkerData, TESForm, AlchemyItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
class REFR_LIGHT; class REFR_LOCK; class DoorTeleportData; class MapMarkerData; class TESForm; class AlchemyItem;
enum class ExtraDataType { kDetachTime = 0x0a, kOwnership = 0x21, kLight = 0x29, kLock = 0x2a, kTeleport = 0x2b, kMapMarker = 0x2c, kPoison = 0x3e, kHotkey = 0x49, kLockList = 0xa3 };
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
class ExtraDetachTime : public BSExtraData { public: std::uint32_t time; };
class ExtraPoison : public BSExtraData { public: AlchemyItem* poison; std::uint32_t count; };
class ExtraLight : public BSExtraData { public: REFR_LIGHT* lightData; };
class ExtraLock : public BSExtraData { public: REFR_LOCK* lock; };
class ExtraTeleport : public BSExtraData { public: DoorTeleportData* teleportData; };
class ExtraMapMarker : public BSExtraData { public: MapMarkerData* mapData; };
class ExtraOwnership : public BSExtraData { public: TESForm* owner; };
class ExtraLockList : public BSExtraData { public: TESForm* list; };
class ExtraDataList { public:
 BSExtraData* GetByType(ExtraDataType type);
 bool HasHotkey();
 std::uint32_t QueryDetachTime();
 std::uint32_t GetPoisonCount();
 REFR_LIGHT* GetLightData();
 REFR_LOCK* GetLockData();
 DoorTeleportData* GetTeleportData();
 MapMarkerData* GetMapMarkerData();
 TESForm* GetOwner();
 TESForm* QueryLockList();
 };
