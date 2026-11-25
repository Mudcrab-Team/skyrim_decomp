// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxStream: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond78140: GUESS(low); provisional member name
// 0xd78140 GFxStream::Functiond78140
// CI hash: 0xd78140 ?Functiond78140@GFxStream@@QEAAXPEAE_K@Z
#include "GFxStream_d78140.h"

// Guess: Read bytes from the input buffer after resetting its bit position.
void GFxStream::Functiond78140(unsigned char* output, std::size_t count)
{
    for (std::size_t i = 0; i < count; ++i) {
        auto* stream = input;
        stream->bitPosition = 0;
        if (static_cast<int>(stream->size - stream->position) < 1) { stream->Refill(1); }
        unsigned offset = stream->position;
        unsigned char value = stream->data[offset];
        stream->position = offset + 1;
        output[i] = value;
    }
}
