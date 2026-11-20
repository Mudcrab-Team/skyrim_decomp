// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSCreatedObjectManager; size 0xd0
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BGSCreatedObjectManager__CreatedMagicItemData_ff5b84f4.h"
#include "BSTScatterTable_RE__BSCRC32_RE__MagicItem_std__equal_to_RE__MagicItem_RE__BSTSetTraits_c71c3038.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_dcee5d18.h"
#include "BSTSingletonSDM_RE__BGSCreatedObjectManager_28793d43.h"
struct BGSCreatedObjectManager {
    BSTSingletonSDM_RE__BGSCreatedObjectManager_28793d43 _base;
    unsigned char pad01;
    unsigned short pad02;
    unsigned int pad04;
    BSTArray_RE__BGSCreatedObjectManager__CreatedMagicItemData_ff5b84f4 weaponEnchantments;
    BSTArray_RE__BGSCreatedObjectManager__CreatedMagicItemData_ff5b84f4 armorEnchantments;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_dcee5d18 potions;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_dcee5d18 poisons;
    BSTScatterTable_RE__BSCRC32_RE__MagicItem_std__equal_to_RE__MagicItem_RE__BSTSetTraits_c71c3038 queuedDeletes;
    BSSpinLock lock;
};
static_assert(sizeof(BGSCreatedObjectManager) == 208, "BGSCreatedObjectManager layout differs from the PDB");
