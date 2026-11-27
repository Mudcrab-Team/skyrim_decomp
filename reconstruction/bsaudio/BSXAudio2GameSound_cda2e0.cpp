// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// BSXAudio2GameSound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSXAudio2GameSound::Functioncda2e0: GUESS(low)
// 0xcda2e0 BSXAudio2GameSound::Functioncda2e0
#include "BSXAudio2GameSound_cda2e0.h"

#include <cmath>

// Update the emitter position, recompute listener distance, and trigger initial positioning.
void BSXAudio2GameSound::Functioncda2e0(const NiPoint3& a_pos)
{
    if (TestBit(soundType, 10)) {
        emitterPosition = gAudioOrigin->position;
    } else {
        emitterPosition.x = a_pos.x;
        emitterPosition.y = a_pos.z;
        emitterPosition.z = a_pos.y;
    }

    const NiPoint3* listener = Functioncccf30(BSAudioManager::Functioncca610());
    const float dx = a_pos.x - listener->x;
    const float dy = a_pos.y - listener->y;
    const float dz = a_pos.z - listener->z;
    listenerDistance = std::sqrt(dy * dy + dx * dx + dz * dz);

    if (!TestBit(flags, 20)) {
        flags |= (1u << 20);
        Unk_0D();
    }
}
