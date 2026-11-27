// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x1515230 BSGraphics::Renderer::SubmitAccumulator
#include "Renderer_1515230.h"

namespace BSGraphics
{
    void Renderer::SubmitAccumulator(NiCamera* camera, BSShaderAccumulator* accumulator, unsigned flags)
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
        accumulator->FinishAccumulatingPostResolveDepth(flags);
    }
}
