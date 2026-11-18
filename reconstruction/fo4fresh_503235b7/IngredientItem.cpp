// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:52
// ClearData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:60
// IngredientItem, IngredientItem::InitializeData, IngredientItem::ClearData: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, cost, flags, InitializeMagicData, RemoveAllEffects, ClearFormData: STANDIN GUESS(low)
// 0x14edb0 IngredientItem::InitializeData
// 0x14edd0 IngredientItem::ClearData
#include "IngredientItem.h"

void IngredientItem::InitializeData() { cost = -1; flags = 0; InitializeMagicData(); }
void IngredientItem::ClearData() { RemoveAllEffects(); ClearFormData(); }
