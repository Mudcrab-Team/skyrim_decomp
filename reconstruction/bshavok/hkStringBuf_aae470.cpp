// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkStringBuf: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaae470: GUESS(low); provisional member name
// 0xaae470 hkStringBuf::Functionaae470
// CI hash: 0xaae470 ?Functionaae470@hkStringBuf@@QEAAXHPEBDH@Z
#include "hkStringBuf_aae470.h"

// Guess: Resolve an implicit string length before insertion.
void hkStringBuf::Functionaae470(int index, const char* text, int length)
{
    if (length < 0) { length = StringLength(text); }
    Insert(&stringAllocatorAae470, index, text, length);
}
