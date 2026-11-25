// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxStream: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond456b0: GUESS(low); provisional member name
// 0xd456b0 GFxStream::Functiond456b0
// CI hash: 0xd456b0 ?Functiond456b0@GFxStream@@QEAA_JXZ
#include "GFxStream_d456b0.h"

// Guess: Calculate the stream position after accounting for buffered data.
std::int64_t GFxStream::Functiond456b0()
{
    int buffered = end - position + base;
    return static_cast<int>(Tell()) - buffered;
}
