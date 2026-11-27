// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncd5de0: GUESS(low)
// 0xcd5de0 BSXAudio2GameSound::Functioncd5de0
#include "BSXAudio2GameSound_cd5de0.h"

// Query the sound category virtual predicate when a category is assigned.
bool BSXAudio2GameSound::Functioncd5de0()
{
    return category && category->Unk_01();
}
