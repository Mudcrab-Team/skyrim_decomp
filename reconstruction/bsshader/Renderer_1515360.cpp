// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x1515360 BSGraphics::Renderer::FinishAccumulatingPostResolveDepth
#include "Renderer_1515360.h"

void BSGraphics::Renderer::FinishAccumulatingPostResolveDepth(NiCamera*, BSShaderAccumulator* accumulator, std::uint32_t flags)
{
    accumulator->FinishAccumulatingPostResolveDepth(flags);
}
