// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x150a0a0 BSImagespaceShaderDepthOfFieldMaskedFogged::Unk_0D
// Adapted bodies: none
// firstBinding, secondBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderDepthOfFieldMaskedFogged_150a0a0.h"

extern const char firstBinding[];
extern const char secondBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderDepthOfFieldMaskedFogged::Unk_0D(const void** bindings)
{
    *bindings++ = firstBinding;
    const char* empty = kEmptyString;
    *bindings++ = empty;
    *bindings++ = secondBinding;
    *bindings++ = empty;
    *bindings++ = nullptr;
    *bindings++ = nullptr;
    return bindings - 6;
}
