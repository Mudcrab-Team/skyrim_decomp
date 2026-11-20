// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterRestore: EXE_RTTI
// AutoRegisterCombatMagicCasterRestoreLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterRestore;
class AutoRegisterCombatMagicCasterRestoreLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterRestore>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterRestore>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterRestore>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterRestore>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterRestore>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterRestore>> {
public:
    AutoRegisterCombatMagicCasterRestoreLayout();
    ~AutoRegisterCombatMagicCasterRestoreLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterRestoreLayout) == 48, "reconciled registration owner size");
}
