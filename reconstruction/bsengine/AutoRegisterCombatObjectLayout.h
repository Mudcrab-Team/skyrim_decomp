// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatObject, CombatInventoryItemMagicT: EXE_RTTI
// AutoRegisterCombatObjectLayout: GUESS(medium) STANDIN
// CombatInventoryItemPotion, CombatInventoryItemScroll: EXE_RTTI
// Product, Inventory, Caster: GUESS(medium); template-parameter spellings
#pragma once
namespace ResearchLayouts {
class CombatInventoryItemMagic;
class CombatInventoryItemShout;
class CombatInventoryItemStaff;
class CombatInventoryItemPotion;
class CombatInventoryItemScroll;
template<class Inventory, class Caster> class CombatInventoryItemMagicT;
template<class Product>
class AutoRegisterCombatObjectLayout {
public:
    AutoRegisterCombatObjectLayout();
    virtual ~AutoRegisterCombatObjectLayout();
};
static_assert(sizeof(AutoRegisterCombatObjectLayout<void>) == sizeof(void*), "fieldless registration base");
}
