// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/AlchemyItem.cpp:20
// ClearData: Sibling source: fo4-private@1b765c70 src/Shared/Magic/AlchemyItem.cpp:31
// AlchemyItem, AlchemyItem::InitializeData, AlchemyItem::ClearData: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, cost, flags, InitializeMagicData, RemoveAllEffects, ClearFormData: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class AlchemyItem {
public:
    void InitializeData();
    void ClearData();
private:
    void InitializeMagicData();
    void RemoveAllEffects();
    void ClearFormData();
    std::uint64_t unknown00[39];
    int cost;
    std::uint32_t flags;
    void* addictionItem;
    float addictionChance;
    void* consumptionSound;
};
