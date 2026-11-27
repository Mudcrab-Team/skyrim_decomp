// Code origin: adapted from fo4-private@1b765c70 src/Game/AI/Combat/CombatAimController.cpp:153; target-specific reconstruction.
// Source exposure: mixed
// CombatAimController, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// CalculatePriority: SYMBOLS(tesv-2013-map) SIBLING(fo4-private@1b765c70, author-permission)
// PRIORITY: CRASHLOGGER_PDB(59818@2026.10.24)
// unknown00: GUESS(low); unaccessed prefix.

#pragma once

#include <cstdint>
#include <cstddef>

enum class PRIORITY : int;

class CombatAimController
{
public:
    unsigned int CalculatePriority(PRIORITY priority) const;

    unsigned char unknown00[0x3C];
    std::uint32_t flags;
};
static_assert(offsetof(CombatAimController, flags) == 0x3C, "flag offset");
