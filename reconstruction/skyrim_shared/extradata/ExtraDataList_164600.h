// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetPoison: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:727
// ExtraDataList::GetPoison: SIBLING(fo4-private@1b765c70, author-permission)
// AlchemyItem, QPoison: STANDIN GUESS(low)
// GetPersistentCell: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:1766
// GetEncounterZone: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:2795
// GetPrimitive: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:2289
// GetCombatStyle: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3240
// GetEnchantment: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3250
// GetRank: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:605
// GetCount: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:677
// RemoveSavedAnimation: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3052
// RemoveSavedHavokData: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:3092
// ExtraDataList, ExtraDataList::RemoveSavedAnimation, ExtraDataList::RemoveSavedHavokData, ExtraDataList::GetPersistentCell, ExtraDataList::GetEncounterZone, ExtraDataList::GetPrimitive, ExtraDataList::GetCombatStyle, ExtraDataList::GetEnchantment, ExtraDataList::GetRank, ExtraDataList::GetCount: SIBLING(fo4-private@1b765c70, author-permission)
// ExtraData, unknown00, value, GetExtraData, RemoveExtra: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class TESObjectCELL;
class BGSEncounterZone;
class BGSPrimitive;
class TESCombatStyle;
class EnchantmentItem;
class AlchemyItem;
struct ExtraData { AlchemyItem* QPoison(); std::uint64_t unknown00[2]; union { void* value; int rank; short count; }; };
class ExtraDataList {
public:
    TESObjectCELL* GetPersistentCell() const;
    BGSEncounterZone* GetEncounterZone() const;
    BGSPrimitive* GetPrimitive() const;
    TESCombatStyle* GetCombatStyle() const;
    EnchantmentItem* GetEnchantment() const;
    AlchemyItem* GetPoison() const;
    int GetRank() const;
    short GetCount() const;
    void RemoveSavedAnimation();
    void RemoveSavedHavokData();
private:
    ExtraData* GetExtraData(unsigned int) const;
    void RemoveExtra(unsigned int);
};
