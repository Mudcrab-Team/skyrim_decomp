// Source exposure: mixed (pinned image, community declarations and CrashLogger names).
// Code origin: original reconstruction with extra-data type names from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// BSExtraDataList, BSExtraDataList::RemoveExtraDataByType: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, ExtraDataType, ExtraDataList::GetByType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kContainerChanges, kPackageStartLocation, kFollower, kOwnership, kCount, kHealth, kTimeLeft, kCharge: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kLight, kLock, kTeleport, kLeveledItem, kScale, kMagicLight, kLastFinishedSequence, kFriendHits: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kRefractionProperty, kHotkey, kInfoGeneralTopic, kHasNoRumors, kCanTalkToPlayer, kObjectHealth, kNavMeshPortal, kModelSwap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kDismemberedLimbs, kActorCause, kMultiBoundMarkerData, kAmmo, kAliasInstanceArray, kGIDBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetFollower, RemoveHotkey, RemoveInfoGeneralTopic, RemoveFriendHits, GetRefractionProperty, GetLeveledItem, RemoveHasNoRumors, GetMultiBoundMarkerData: GUESS(low)
// RemoveLight, RemoveMagicLight, RemoveLock, RemoveTeleport, RemoveOwnership, RemoveHealth, RemoveCount, RemoveTimeLeft: GUESS(low)
// RemoveCharge, RemoveScale, RemoveContainerChanges, RemovePackageStartLocation, RemoveLastFinishedSequence, RemoveModelSwap, GetNavMeshPortal, GetCanTalkToPlayer: GUESS(low)
// RemoveObjectHealth, GetDismemberedLimbs, GetActorCause, GetAmmo, GetAliasInstanceArray, RemoveGIDBuffer: GUESS(low)
// 0x162d00 BSExtraDataList::GetFollower
// 0x163990 BSExtraDataList::RemoveHotkey
// 0x163ce0 BSExtraDataList::RemoveInfoGeneralTopic
// 0x163e20 BSExtraDataList::RemoveFriendHits
// 0x164140 BSExtraDataList::GetRefractionProperty
// 0x164830 BSExtraDataList::GetLeveledItem
// 0x1695f0 BSExtraDataList::RemoveHasNoRumors
// 0x16a760 BSExtraDataList::GetMultiBoundMarkerData
// 0x16e7b0 BSExtraDataList::RemoveLight
// 0x16e7c0 BSExtraDataList::RemoveMagicLight
// 0x16e7d0 BSExtraDataList::RemoveLock
// 0x16e7e0 BSExtraDataList::RemoveTeleport
// 0x16e800 BSExtraDataList::RemoveOwnership
// 0x16e860 BSExtraDataList::RemoveHealth
// 0x16e870 BSExtraDataList::RemoveCount
// 0x16e880 BSExtraDataList::RemoveTimeLeft
// 0x16e890 BSExtraDataList::RemoveCharge
// 0x16e920 BSExtraDataList::RemoveScale
// 0x16e940 BSExtraDataList::RemoveContainerChanges
// 0x16e950 BSExtraDataList::RemovePackageStartLocation
// 0x16eda0 BSExtraDataList::RemoveLastFinishedSequence
// 0x16fc00 BSExtraDataList::RemoveModelSwap
// 0x16fc10 BSExtraDataList::GetNavMeshPortal
// 0x1702b0 BSExtraDataList::GetCanTalkToPlayer
// 0x170f00 BSExtraDataList::RemoveObjectHealth
// 0x171370 BSExtraDataList::GetDismemberedLimbs
// 0x1713f0 BSExtraDataList::GetActorCause
// 0x171680 BSExtraDataList::GetAmmo
// 0x1728d0 BSExtraDataList::GetAliasInstanceArray
// 0x173530 BSExtraDataList::RemoveGIDBuffer
#include "BSExtraDataList.h"

BSExtraData* BSExtraDataList::GetFollower() const
{
    return GetByType(ExtraDataType::kFollower);
}

void BSExtraDataList::RemoveHotkey()
{
    RemoveExtraDataByType(ExtraDataType::kHotkey);
}

void BSExtraDataList::RemoveInfoGeneralTopic()
{
    RemoveExtraDataByType(ExtraDataType::kInfoGeneralTopic);
}

void BSExtraDataList::RemoveFriendHits()
{
    RemoveExtraDataByType(ExtraDataType::kFriendHits);
}

BSExtraData* BSExtraDataList::GetRefractionProperty() const
{
    return GetByType(ExtraDataType::kRefractionProperty);
}

BSExtraData* BSExtraDataList::GetLeveledItem() const
{
    return GetByType(ExtraDataType::kLeveledItem);
}

void BSExtraDataList::RemoveHasNoRumors()
{
    RemoveExtraDataByType(ExtraDataType::kHasNoRumors);
}

BSExtraData* BSExtraDataList::GetMultiBoundMarkerData() const
{
    return GetByType(ExtraDataType::kMultiBoundMarkerData);
}

void BSExtraDataList::RemoveLight()
{
    RemoveExtraDataByType(ExtraDataType::kLight);
}

void BSExtraDataList::RemoveMagicLight()
{
    RemoveExtraDataByType(ExtraDataType::kMagicLight);
}

void BSExtraDataList::RemoveLock()
{
    RemoveExtraDataByType(ExtraDataType::kLock);
}

void BSExtraDataList::RemoveTeleport()
{
    RemoveExtraDataByType(ExtraDataType::kTeleport);
}

void BSExtraDataList::RemoveOwnership()
{
    RemoveExtraDataByType(ExtraDataType::kOwnership);
}

void BSExtraDataList::RemoveHealth()
{
    RemoveExtraDataByType(ExtraDataType::kHealth);
}

void BSExtraDataList::RemoveCount()
{
    RemoveExtraDataByType(ExtraDataType::kCount);
}

void BSExtraDataList::RemoveTimeLeft()
{
    RemoveExtraDataByType(ExtraDataType::kTimeLeft);
}

void BSExtraDataList::RemoveCharge()
{
    RemoveExtraDataByType(ExtraDataType::kCharge);
}

void BSExtraDataList::RemoveScale()
{
    RemoveExtraDataByType(ExtraDataType::kScale);
}

void BSExtraDataList::RemoveContainerChanges()
{
    RemoveExtraDataByType(ExtraDataType::kContainerChanges);
}

void BSExtraDataList::RemovePackageStartLocation()
{
    RemoveExtraDataByType(ExtraDataType::kPackageStartLocation);
}

void BSExtraDataList::RemoveLastFinishedSequence()
{
    RemoveExtraDataByType(ExtraDataType::kLastFinishedSequence);
}

void BSExtraDataList::RemoveModelSwap()
{
    RemoveExtraDataByType(ExtraDataType::kModelSwap);
}

BSExtraData* BSExtraDataList::GetNavMeshPortal() const
{
    return GetByType(ExtraDataType::kNavMeshPortal);
}

BSExtraData* BSExtraDataList::GetCanTalkToPlayer() const
{
    return GetByType(ExtraDataType::kCanTalkToPlayer);
}

void BSExtraDataList::RemoveObjectHealth()
{
    RemoveExtraDataByType(ExtraDataType::kObjectHealth);
}

BSExtraData* BSExtraDataList::GetDismemberedLimbs() const
{
    return GetByType(ExtraDataType::kDismemberedLimbs);
}

BSExtraData* BSExtraDataList::GetActorCause() const
{
    return GetByType(ExtraDataType::kActorCause);
}

BSExtraData* BSExtraDataList::GetAmmo() const
{
    return GetByType(ExtraDataType::kAmmo);
}

BSExtraData* BSExtraDataList::GetAliasInstanceArray() const
{
    return GetByType(ExtraDataType::kAliasInstanceArray);
}

void BSExtraDataList::RemoveGIDBuffer()
{
    RemoveExtraDataByType(ExtraDataType::kGIDBuffer);
}
