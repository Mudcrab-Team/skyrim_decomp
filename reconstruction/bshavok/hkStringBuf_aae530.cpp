// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkStringBuf: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaae530: GUESS(low); provisional member name
// 0xaae530 hkStringBuf::Functionaae530
// CI hash: 0xaae530 ?Functionaae530@hkStringBuf@@QEAAXXZ
#include "hkStringBuf_aae530.h"

// Guess: Retain the directory part before the last path separator.
void hkStringBuf::Functionaae530()
{
    int slash = FindLast('/', 0, 0x7fffffff);
    int backslash = FindLast('\\', 0, 0x7fffffff);
    int end = backslash > slash ? backslash : slash;
    if (end >= 0) { Substring(0, end); }
    else { Clear(); }
}
