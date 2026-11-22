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
#pragma once

class BSExtraData;

enum class ExtraDataType
{
    kContainerChanges = 0x15,
    kPackageStartLocation = 0x18,
    kFollower = 0x1d,
    kOwnership = 0x21,
    kCount = 0x24,
    kHealth = 0x25,
    kTimeLeft = 0x27,
    kCharge = 0x28,
    kLight = 0x29,
    kLock = 0x2a,
    kTeleport = 0x2b,
    kLeveledItem = 0x2e,
    kScale = 0x2f,
    kMagicLight = 0x3f,
    kLastFinishedSequence = 0x40,
    kFriendHits = 0x44,
    kRefractionProperty = 0x47,
    kHotkey = 0x49,
    kInfoGeneralTopic = 0x4c,
    kHasNoRumors = 0x4d,
    kCanTalkToPlayer = 0x54,
    kObjectHealth = 0x55,
    kNavMeshPortal = 0x57,
    kModelSwap = 0x58,
    kDismemberedLimbs = 0x5c,
    kActorCause = 0x5d,
    kMultiBoundMarkerData = 0x5f,
    kAmmo = 0x6a,
    kAliasInstanceArray = 0x88,
    kGIDBuffer = 0xb2,
};

class BSExtraDataList
{
public:
    BSExtraData* GetFollower() const;
    void RemoveHotkey();
    void RemoveInfoGeneralTopic();
    void RemoveFriendHits();
    BSExtraData* GetRefractionProperty() const;
    BSExtraData* GetLeveledItem() const;
    void RemoveHasNoRumors();
    BSExtraData* GetMultiBoundMarkerData() const;
    void RemoveLight();
    void RemoveMagicLight();
    void RemoveLock();
    void RemoveTeleport();
    void RemoveOwnership();
    void RemoveHealth();
    void RemoveCount();
    void RemoveTimeLeft();
    void RemoveCharge();
    void RemoveScale();
    void RemoveContainerChanges();
    void RemovePackageStartLocation();
    void RemoveLastFinishedSequence();
    void RemoveModelSwap();
    BSExtraData* GetNavMeshPortal() const;
    BSExtraData* GetCanTalkToPlayer() const;
    void RemoveObjectHealth();
    BSExtraData* GetDismemberedLimbs() const;
    BSExtraData* GetActorCause() const;
    BSExtraData* GetAmmo() const;
    BSExtraData* GetAliasInstanceArray() const;
    void RemoveGIDBuffer();

private:
    BSExtraData* GetByType(ExtraDataType a_type) const;
    void RemoveExtraDataByType(ExtraDataType a_type);
};
