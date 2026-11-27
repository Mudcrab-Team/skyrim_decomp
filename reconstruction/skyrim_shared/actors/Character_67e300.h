// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Function67e300, Function6afef0, unkE8: GUESS(low)
// Character::sub_1405DA020: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

class Character
{
public:
    bool Function67e300();  // compared: 0x67e300; placeholder Character::sub_1405DA020
    void Function6afef0();  // callee, matched elsewhere

    char unk00[0xE8];
    std::uint32_t unkE8;
};
