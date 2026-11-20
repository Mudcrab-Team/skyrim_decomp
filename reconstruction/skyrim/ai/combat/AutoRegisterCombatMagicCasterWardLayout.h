// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterWard: EXE_RTTI
// AutoRegisterCombatMagicCasterWardLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterWard;
class AutoRegisterCombatMagicCasterWardLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterWard>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterWard>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterWard>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterWard>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterWard>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterWard>> {
public:
    AutoRegisterCombatMagicCasterWardLayout();
    ~AutoRegisterCombatMagicCasterWardLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterWardLayout) == 48, "reconciled registration owner size");
}
