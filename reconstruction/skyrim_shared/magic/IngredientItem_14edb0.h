// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:52
// ClearData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/IngredientItem.cpp:60
// IngredientItem, IngredientItem::InitializeData, IngredientItem::ClearData: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, cost, flags, InitializeMagicData, RemoveAllEffects, ClearFormData: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class IngredientItem {
public:
    void InitializeData();
    void ClearData();
private:
    void InitializeMagicData();
    void RemoveAllEffects();
    void ClearFormData();
    std::uint64_t unknown00[38];
    int cost;
    std::uint32_t flags;
};
