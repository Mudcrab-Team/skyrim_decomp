// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESSoulGem.cpp:135 (TESSoulGem::GetSoulLevelValue)
// TESSoulGem: GUESS(low)
// TESSoulGem::GetSoulLevelValue: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
// 0x28ef80 TESSoulGem::GetSoulLevelValue
#include "TESSoulGem_28ef80.h"
unsigned int TESSoulGem::GetSoulLevelValue(SOUL_LEVEL soul) {
    unsigned int value = 0;
    switch (soul) {
    case PETTY: value = petty; break;
    case LESSER: value = lesser; break;
    case COMMON: value = common; break;
    case GREATER: value = greater; break;
    case GRAND: value = grand; break;
    default: break;
    }
    return value;
}
