// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSAudioManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionccd2c0: GUESS(low); provisional member name
// 0xccd2c0 BSAudioManager::Functionccd2c0
// CI hash: 0xccd2c0 ?Functionccd2c0@BSAudioManager@@QEAAXPEBDI@Z
#include "BSAudioManager_ccd2c0.h"

// Guess: Resolve an audio identity through the callback and apply its flags.
void BSAudioManager::Functionccd2c0(const char* identity, unsigned flags)
{
    Scopeccd2c0 scope(0x2c);
    void* sound = nullptr;
    if (resolve && resolve(identity, &sound) && sound) { Apply(sound, flags); }
}
