// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSAudioManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionccd360: GUESS(low); provisional member name
// 0xccd360 BSAudioManager::Functionccd360
// CI hash: 0xccd360 ?Functionccd360@BSAudioManager@@QEAAXII@Z
#include "BSAudioManager_ccd360.h"

// Guess: Resolve an audio identity through the callback and apply its flags.
void BSAudioManager::Functionccd360(unsigned identity, unsigned flags)
{
    Scopeccd360 scope(0x2c);
    void* sound = nullptr;
    if (resolve && resolve(identity, &sound) && sound) { Apply(sound, flags); }
}
