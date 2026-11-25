// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x15152d0 BSGraphics::Renderer::StartAccumulating
#include "Renderer_15152d0.h"

namespace BSGraphics
{
    void Renderer::StartAccumulating(NiCamera* camera, BSShaderAccumulator* accumulator, unsigned flags)
    {
        if (camera) {
            graphicsState.SetCameraData(camera, flags);
            constexpr unsigned updateViewport = 1u << 10;
            if (flags & updateViewport) {
                renderer.UpdateViewPort(0, 0, true);
            }
            currentCamera = camera;
            BSShaderAccumulator::SetCurrentAccumulator(accumulator);
            accumulator->StartAccumulating(camera);
            accumulator->FinishAccumulatingPreResolveDepth(flags);
        }
    }
}
