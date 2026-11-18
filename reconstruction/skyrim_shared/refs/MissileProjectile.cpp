// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x7f4d40 MissileProjectile::GetKillOnCollision
// 0x7f4dc0 MissileProjectile::LoadGame
// 0x7f4e10 MissileProjectile::FinishLoadGame
// 0x7f4d70 MissileProjectile::SaveGame
#include "MissileProjectile.h"

// RVA 0x7f4d40, 11 bytes, MissileProjectile::GetKillOnCollision.
bool MissileProjectile::GetKillOnCollision()
{
    return impactResult == ImpactResult::kDestroy;
}

// RVA 0x7f4dc0, 55 bytes, MissileProjectile::LoadGame.
void MissileProjectile::LoadGame(BGSLoadFormBuffer* a_buf)
{
    PrepareLoad();
    a_buf->LoadDataEndian(&impactResult, 4, 4);
}

// RVA 0x7f4e10, 57 bytes, MissileProjectile::FinishLoadGame.
// The buffer is not read here; a missing saved state marks the object for later initialisation.
void MissileProjectile::FinishLoadGame(BGSLoadFormBuffer* /*a_buf*/)
{
    PrepareFinishLoad();
    if (unk70() != nullptr) {
        ContinueFinishLoad();
        return;
    }
    unk1E4 = 1;
}

// RVA 0x7f4d70, 64 bytes, MissileProjectile::SaveGame.
void MissileProjectile::SaveGame(BGSSaveFormBuffer* a_buf)
{
    PrepareSave();
    a_buf->SaveDataEndian(&impactResult, 4, 4, 0);
}

// Accepted leaf retained from the integrated version.
// Slot162: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t MissileProjectile::Slot162() const
{
    return 0x1;
}
