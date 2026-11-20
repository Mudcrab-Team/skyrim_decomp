// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterStagger: EXE_RTTI
// AutoRegisterCombatMagicCasterStaggerLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterStagger;
class AutoRegisterCombatMagicCasterStaggerLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterStagger>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterStagger>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterStagger>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterStagger>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterStagger>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterStagger>> {
public:
    AutoRegisterCombatMagicCasterStaggerLayout();
    ~AutoRegisterCombatMagicCasterStaggerLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterStaggerLayout) == 48, "reconciled registration owner size");
}
