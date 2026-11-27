// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x743e50 PlayerCharacter::sub_14069D220
// Adapted bodies: none
#include "PlayerCharacter_743e50.h"

// Copy the state record into the player's embedded block at offset 0x650.
void PlayerCharacter::sub_14069D220(const PlayerData650* a_src)
{
    unk650.unk00 = a_src->unk00;
    unk650.unk08 = a_src->unk08;
    unk650.unk10 = a_src->unk10;
    unk650.unk14 = a_src->unk14;
    unk650.unk18 = a_src->unk18;
    unk650.unk1C = a_src->unk1C;
    unk650.unk20 = a_src->unk20;
    unk650.unk24 = a_src->unk24;
    unk650.unk28 = a_src->unk28;
    unk650.unk30 = a_src->unk30;
    unk650.unk38 = a_src->unk38;
    unk650.unk3C = a_src->unk3C;
    unk650.unk40 = a_src->unk40;
    unk650.unk42 = a_src->unk42;
    unk650.unk41 = a_src->unk41;
}
