// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// RefrInteraction, RefrInteraction::FinishLoadGame: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x78c850 RefrInteraction::FinishLoadGame
#include "RefrInteraction_78c850.h"

// Runs post-load virtual setup and synchronizes the interaction when flagged.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void RefrInteraction::FinishLoadGame()
{
    Unk_0C();
    if (synced)
    {
        Unk_08();
    }
}
