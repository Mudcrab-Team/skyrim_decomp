// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/AlchemyItem.cpp:20
// ClearData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/AlchemyItem.cpp:31
// AlchemyItem, AlchemyItem::InitializeData, AlchemyItem::ClearData: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, cost, flags, InitializeMagicData, RemoveAllEffects, ClearFormData: STANDIN GUESS(low)
// 0x145af0 AlchemyItem::InitializeData
// 0x145b30 AlchemyItem::ClearData
#include "AlchemyItem_145af0.h"

void AlchemyItem::InitializeData() { cost = -1; flags = 0; addictionItem = nullptr; addictionChance = 0.0f; consumptionSound = nullptr; InitializeMagicData(); }
void AlchemyItem::ClearData() { RemoveAllEffects(); ClearFormData(); }
