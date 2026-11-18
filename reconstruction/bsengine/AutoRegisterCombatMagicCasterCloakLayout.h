// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterCloak: EXE_RTTI
// AutoRegisterCombatMagicCasterCloakLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterCloak;
class AutoRegisterCombatMagicCasterCloakLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterCloak>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterCloak>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterCloak>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterCloak>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterCloak>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterCloak>> {
public:
    AutoRegisterCombatMagicCasterCloakLayout();
    ~AutoRegisterCombatMagicCasterCloakLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterCloakLayout) == 48, "reconciled registration owner size");
}
