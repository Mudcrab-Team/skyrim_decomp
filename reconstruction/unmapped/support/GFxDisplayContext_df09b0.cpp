// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0xdf09b0 GFxDisplayContext::EndClipLayer
#include "GFxDisplayContext_df09b0.h"

// Decrements clip depth and disables masking when the outermost clip layer ends.
void GFxDisplayContext::EndClipLayer()
{
    if (--clipDepth == 0)
    {
        renderConfig->renderer->DisableMask();
        maskStackSize = 0;
    }
}
