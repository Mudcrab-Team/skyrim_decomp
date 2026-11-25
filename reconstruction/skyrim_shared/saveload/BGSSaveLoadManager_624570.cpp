// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function624570: GUESS(low); provisional member name
// 0x624570 BGSSaveLoadManager::Function624570
// CI hash: 0x624570 ?Function624570@BGSSaveLoadManager@@QEAAXPEBD@Z
#include "BGSSaveLoadManager_624570.h"

// Guess: Remove a known save-file entry before processing the file.
void BGSSaveLoadManager::Function624570(const char* file)
{
    if (files.Contains(file)) { files.Remove(file); }
    Process(file);
}
