// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cb990: GUESS(low); provisional member name
// 0x1cb990 TESFile::Function1cb990
// CI hash: 0x1cb990 ?Function1cb990@TESFile@@QEAAXPEAUSystemTime1cb990@@@Z
#include "TESFile_1cb990.h"

// Guess: Convert the file timestamp to local calendar fields.
void TESFile::Function1cb990(SystemTime1cb990* output)
{
    FileTime1cb990 local;
    ToLocalTime(&time, &local);
    ToSystemTime(&local, output);
}
