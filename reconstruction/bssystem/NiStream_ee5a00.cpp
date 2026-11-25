// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiStream: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionee5a00: GUESS(low); provisional member name
// 0xee5a00 NiStream::Functionee5a00
// CI hash: 0xee5a00 ?Functionee5a00@NiStream@@QEAAXPEBD@Z
#include "NiStream_ee5a00.h"

// Guess: Copy a nonempty stream path and normalize it.
void NiStream::Functionee5a00(const char* text)
{
    if (text && text[0]) {
        CopyPath(path, 260, text, 259);
        NormalizePath(path);
    } else { path[0] = 0; }
}
