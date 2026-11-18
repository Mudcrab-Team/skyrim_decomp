// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterReanimate: EXE_RTTI
// AutoRegisterCombatMagicCasterReanimateLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterReanimate;
class AutoRegisterCombatMagicCasterReanimateLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterReanimate>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterReanimate>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterReanimate>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterReanimate>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterReanimate>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterReanimate>> {
public:
    AutoRegisterCombatMagicCasterReanimateLayout();
    ~AutoRegisterCombatMagicCasterReanimateLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterReanimateLayout) == 48, "reconciled registration owner size");
}
