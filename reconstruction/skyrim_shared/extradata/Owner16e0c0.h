// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: Stamped as a twin of matched 0x169c30 (skyrim_shared/extradata/ExtraDataList_164600): source copied, names replaced by placeholders.
// GetPoison: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:727
// AlchemyItem: STANDIN GUESS(low)
// GetPersistentCell: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:1766
// GetEncounterZone: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:2795
// GetPrimitive: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:2289
// GetCombatStyle: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3240
// GetEnchantment: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3250
// GetRank: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:605
// GetCount: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:677
// RemoveSavedAnimation: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3052
// RemoveSavedHavokData: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3092
// ExtraData, GetExtraData, RemoveExtra: STANDIN GUESS(low)
// Function16e0c0, Owner16e0c0: GUESS(low) STANDIN
#pragma once
#include "ExtraDataList_164600.h"

class Owner16e0c0 {
public:
    TESObjectCELL* GetPersistentCell() const;
    BGSEncounterZone* GetEncounterZone() const;
    BGSPrimitive* GetPrimitive() const;
    TESCombatStyle* GetCombatStyle() const;
    EnchantmentItem* GetEnchantment() const;
    AlchemyItem* Function16e0c0() const;
    int GetRank() const;
    short GetCount() const;
    void RemoveSavedAnimation();
    void RemoveSavedHavokData();
private:
    ExtraData* GetExtraData(unsigned int) const;
    void RemoveExtra(unsigned int);
};

