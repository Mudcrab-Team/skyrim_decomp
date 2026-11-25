// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cee10: GUESS(low); provisional member name
// 0x1cee10 TESFile::Function1cee10
// CI hash: 0x1cee10 ?Function1cee10@TESFile@@QEAAPEAXXZ
#include "TESFile_1cee10.h"

// Guess: Initialize the file cache on first access.
void* TESFile::Function1cee10()
{
    if (!cached) { Build(); }
    return cached;
}
