// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: Stamped as a twin of matched 0x169c30 (skyrim_shared/extradata/ExtraDataList_164600): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// GetPoison: Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/ExtraDataList.cpp:727
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
// 0x16e0c0 Owner16e0c0::Function16e0c0
#include "Owner16e0c0.h"

// guess: same compiled code as matched 0x169c30 apart from relocated fields; its role here is not established.
AlchemyItem* Owner16e0c0::Function16e0c0() const { auto extra = GetExtraData(0x71); return extra ? extra->QPoison() : nullptr; }
