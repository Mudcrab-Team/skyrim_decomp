// Source exposure: mixed (local binary analysis and public names).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// PlayerCharacter: EXE_RTTI
// Slot8: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// PLAYER_ACTION PLAYER_ACTION::kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); int-sized here so the signed range check of the target is kept
// PlayerCharacter::IsActionInList: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// PlayerCharacter::SetBusyActivatingTeleportDoor PlayerCharacter::QWarnToLeave: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// PlayerActionEntry actionList actionListEntryWord: GUESS(low); the 12-byte entries at 0x7f4 as NG's PlayerActionObject, first word compared
// busyUntil: GUESS(low); the float at 0x6e8 written and read by the two teleport door functions
// teleportDoorBusyTime teleportClock: GUESS(low); globals at RVA 0x209eb28 and 0x324430c
#pragma once
#include <cstddef>
#include <cstdint>

enum class PLAYER_ACTION : std::int32_t {
    kTotal = 15,
};

struct PlayerActionEntry {
    std::uint32_t word00;  // 0x00
    std::uint32_t word04;  // 0x04
    std::uint32_t word08;  // 0x08
};
static_assert(sizeof(PlayerActionEntry) == 0xc, "PlayerActionEntry size");

extern const float teleportDoorBusyTime;
extern float       teleportClock;
// Slot8: GUESS(low); method name inferred from vtable owner and slot
class PlayerCharacter
{
public:
    virtual std::uint8_t Slot8() const;
    bool IsActionInList(PLAYER_ACTION a_action) const;
    void SetBusyActivatingTeleportDoor();
    bool QWarnToLeave() const;

    std::uint8_t      pad08[0x6e0];
    float             busyUntil;  // 0x6e8
    std::uint8_t      pad6ec[0x108];
    PlayerActionEntry actionList[static_cast<int>(PLAYER_ACTION::kTotal)];  // 0x7f4
};

static_assert(offsetof(PlayerCharacter, busyUntil) == 0x6e8, "PlayerCharacter::busyUntil offset");
static_assert(offsetof(PlayerCharacter, actionList) == 0x7f4, "PlayerCharacter::actionList offset");
