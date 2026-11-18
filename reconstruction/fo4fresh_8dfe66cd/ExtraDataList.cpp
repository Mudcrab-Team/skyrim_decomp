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
// 0x169c30 ExtraDataList::GetPoison
// 0x16ff80 ExtraDataList::RemoveSavedAnimation
// 0x1701b0 ExtraDataList::RemoveSavedHavokData
// 0x164e50 ExtraDataList::GetPersistentCell
// 0x16a0a0 ExtraDataList::GetEncounterZone
// 0x16d850 ExtraDataList::GetPrimitive
// 0x171550 ExtraDataList::GetCombatStyle
// 0x1732b0 ExtraDataList::GetEnchantment
// 0x164600 ExtraDataList::GetRank
// 0x1648f0 ExtraDataList::GetCount
#include "ExtraDataList.h"

TESObjectCELL* ExtraDataList::GetPersistentCell() const { auto extra = GetExtraData(11); return extra ? static_cast<TESObjectCELL*>(extra->value) : nullptr; }
BGSEncounterZone* ExtraDataList::GetEncounterZone() const { auto extra = GetExtraData(112); return extra ? static_cast<BGSEncounterZone*>(extra->value) : nullptr; }
BGSPrimitive* ExtraDataList::GetPrimitive() const { auto extra = GetExtraData(103); return extra ? static_cast<BGSPrimitive*>(extra->value) : nullptr; }
TESCombatStyle* ExtraDataList::GetCombatStyle() const { auto extra = GetExtraData(101); return extra ? static_cast<TESCombatStyle*>(extra->value) : nullptr; }
EnchantmentItem* ExtraDataList::GetEnchantment() const { auto extra = GetExtraData(155); return extra ? static_cast<EnchantmentItem*>(extra->value) : nullptr; }
int ExtraDataList::GetRank() const { auto extra = GetExtraData(0x23); return extra ? extra->rank : -1; }
short ExtraDataList::GetCount() const { auto extra = GetExtraData(0x24); return extra ? extra->count : 1; }
void ExtraDataList::RemoveSavedAnimation() { RemoveExtra(0x41); }
void ExtraDataList::RemoveSavedHavokData() { RemoveExtra(0x3c); }

AlchemyItem* ExtraDataList::GetPoison() const { auto extra = GetExtraData(0x3e); return extra ? extra->QPoison() : nullptr; }
