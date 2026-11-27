// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0xdf0e00 GFxDisplayContext::BeginClipLayer
#include "GFxDisplayContext_df0e00.h"

// Begins a clip mask layer, renders the clipping character into the mask, and finishes mask submission.
void GFxDisplayContext::BeginClipLayer(GFxCharacter* a_char)
{
    GRenderer* renderer = renderConfig->renderer;
    renderer->BeginSubmitMask(clipDepth != 0 ? 1 : 0);
    if (clipDepth < 64)
    {
        clipObjects[clipDepth] = a_char;
    }
    ++clipDepth;
    ++maskStackSize;
    ++maskDrawDepth;
    renderer->PushBlendMode(a_char->GetBlendMode());
    a_char->Display(*this);
    renderer->PopBlendMode();
    --maskDrawDepth;
    renderer->EndSubmitMask();
}
