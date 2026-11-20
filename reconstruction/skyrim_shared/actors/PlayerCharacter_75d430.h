// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// PlayerCharacter, PlayerCharacter::HasBeenAttacked, PlayerCharacter::IsPowerAttackCoolingDown, PlayerCharacter::SetBeenAttacked: GUESS(low)
// PlayerCharacter fields: STANDIN GUESS(low)
#pragma once
#include <cstdint>
// Package, Process: STANDIN GUESS(low)
struct Package { std::uint8_t pad[0x24]; std::uint8_t type; };
struct Process { std::uint8_t pad[0x20]; Package* package; };
class PlayerCharacter {
public:
    bool HasBeenAttacked(); bool IsPowerAttackCoolingDown() const; void SetBeenAttacked(bool value); bool GetCannibal(); bool GetVampireFeed();
private:
    std::uint8_t pad[0xf8]; Process* process; std::uint8_t gap100[0x814]; float timer; std::uint8_t gap[0x2d1]; std::uint8_t flags; std::uint8_t moreFlags;
};
