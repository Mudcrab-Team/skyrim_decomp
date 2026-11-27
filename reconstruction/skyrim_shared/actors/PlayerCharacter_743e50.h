// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter, sub_14069D220: CRASHLOGGER_PDB(59818@2026.10.24)
// PlayerData650, unk00, unk08, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk30, unk38, unk3C, unk40, unk41, unk42, unk000, unk650: GUESS(low)
// 0x743e50 PlayerCharacter::sub_14069D220
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>

struct PlayerData650
{
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint32_t unk10;
    std::uint32_t unk14;
    std::uint32_t unk18;
    std::uint32_t unk1C;
    std::uint32_t unk20;
    std::uint32_t unk24;
    std::uint64_t unk28;
    std::uint64_t unk30;
    std::uint32_t unk38;
    std::uint32_t unk3C;
    std::uint8_t unk40;
    std::uint8_t unk41;
    std::uint8_t unk42;
};

class PlayerCharacter
{
public:
    void sub_14069D220(const PlayerData650* a_src);

    std::uint8_t unk000[0x650];
    PlayerData650 unk650;
};

static_assert(offsetof(PlayerCharacter, unk650) == 0x650, "unk650 offset");
static_assert(offsetof(PlayerData650, unk42) == 0x42, "unk42 offset");
