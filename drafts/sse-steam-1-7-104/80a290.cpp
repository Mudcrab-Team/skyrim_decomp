// Near miss: 10.0 alignment distance | control-flow
// 0x80a290 CombatAimController::CalculatePriority
// Code origin: adapted from fo4-private@1b765c70 src/Game/AI/Combat/CombatAimController.cpp:153; target-specific reconstruction.
// Source exposure: mixed
// CombatAimController, flags, PRIORITY: CRASHLOGGER_PDB(59818@2026.10.24)
// CalculatePriority: SYMBOLS(tesv-2013-map) SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatAimController.cpp:153
// ReadFlag, bonus: GUESS(low); bit-index accessor and combined-flag priority bonus.
#include "include/80a290/CombatAimController_80a290.h"

static inline bool ReadFlag(unsigned int flags, unsigned int index)
{
    return ((flags >> index) & 1) != 0;
}

unsigned int CombatAimController::CalculatePriority(PRIORITY priority) const
{
    unsigned int result = 0;
    if (static_cast<int>(priority) > 0) {
        unsigned int value = ReadFlag(flags, 6) << 8;
        value += static_cast<unsigned int>(priority);
        value <<= 15;
        value += ReadFlag(flags, 8);
        unsigned int bonus = 0;
        if (static_cast<unsigned char>(flags & 12) == 12)
            bonus = 2;
        value += bonus;
        result = 2 * value + ReadFlag(flags, 2);
    }
    return result;
}
