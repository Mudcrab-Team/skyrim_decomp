// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original implementation from the pinned slot body; the compared body is the compiler-generated scalar deleting destructor from the listing
// 0x1508100 BSImagespaceShaderCopyCustomViewport::dtor
// Adapted bodies: none
#include "BSImagespaceShaderCopyCustomViewport.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSImagespaceShaderCopyCustomViewport::BSImagespaceShaderCopyCustomViewport()
{
}

// ~BSImagespaceShaderCopyCustomViewport stays declared but undefined: the compared
// deleting destructor calls the complete destructor out of line (cookbook rule 18).

const void** BSImagespaceShaderCopyCustomViewport::Unk_0D(const void** bindings)
{
    bindings[0] = nullptr;
    bindings[1] = nullptr;
    return bindings;
}
