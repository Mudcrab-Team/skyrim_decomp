// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1caeb0: GUESS(low); provisional member name
// 0x1caeb0 TESFile::Function1caeb0
// CI hash: 0x1caeb0 ?Function1caeb0@TESFile@@QEAA_NXZ
#include "TESFile_1caeb0.h"

// Guess: Check the full path under the file allocation context.
bool TESFile::Function1caeb0()
{
    Scope1caeb0 scope(8);
    Prepare(0);
    char path[260];
    Copy1caeb0(path, 260, directory);
    Append1caeb0(path, 260, filename);
    return Check1caeb0(path) == 0;
}
