// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cb9d0: GUESS(low); provisional member name
// 0x1cb9d0 TESFile::Function1cb9d0
// CI hash: 0x1cb9d0 ?Function1cb9d0@TESFile@@QEAAXPEAUSystemTime1cb9d0@@@Z
#include "TESFile_1cb9d0.h"

// Guess: Convert the file timestamp to local calendar fields.
void TESFile::Function1cb9d0(SystemTime1cb9d0* output)
{
    FileTime1cb9d0 local;
    ToLocalTime(&time, &local);
    ToSystemTime(&local, output);
}
