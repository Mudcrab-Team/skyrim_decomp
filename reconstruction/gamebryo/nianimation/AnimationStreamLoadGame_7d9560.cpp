// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// AnimationStreamLoadGame: CRASHLOGGER_PDB(59818@2026.10.24)
// LoadTransform: GUESS(low)
// 0x7d9560 AnimationStreamLoadGame::LoadTransform
#include "AnimationStreamLoadGame_7d9560.h"

// Loads translation, scale, and rotation fields from the save game buffer.
// The CrashLogger name is Func2_14072DC60; the name used here is a guess from what the body does.
bool AnimationStreamLoadGame::LoadTransform(TransformData7d9560* a_dest)
{
    buffer->LoadDataEndian(a_dest, 16, 4);
    buffer->LoadDataEndian(a_dest->scale, 16, 4);
    LoadQuat(a_dest->rotation);
    return true;
}
