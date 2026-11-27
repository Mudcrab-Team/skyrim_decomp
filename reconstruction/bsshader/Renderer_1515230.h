// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSGraphics, Renderer, State, NiCamera, BSShaderAccumulator, SubmitAccumulator, SetCameraData, UpdateViewPort, SetCurrentAccumulator, StartAccumulating, FinishAccumulating, RegisterObjectArray, StartGroupingAlphas, StopGroupingAlphas, FinishAccumulatingPreResolveDepth, FinishAccumulatingPostResolveDepth: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// graphicsState, renderer, currentCamera, updateViewport: GUESS(low)
#pragma once

#include "../gamebryo/nimain/NiObject.h"

class NiCamera;
class NiBound;
class NiVisibleArray;
class BSBatchRenderer
{
public:
    class GeometryGroup;
};

class BSShaderAccumulator : public NiObject
{
public:
    static void SetCurrentAccumulator(BSShaderAccumulator* accumulator);
    virtual void StartAccumulating(NiCamera* camera);
    virtual void FinishAccumulating();
    virtual void RegisterObjectArray(NiVisibleArray& objects);
    virtual BSBatchRenderer::GeometryGroup* StartGroupingAlphas(NiBound* bound);
    virtual void StopGroupingAlphas(BSBatchRenderer::GeometryGroup* group);
    virtual void FinishAccumulatingPreResolveDepth(unsigned flags);
    virtual void FinishAccumulatingPostResolveDepth(unsigned flags);
};

namespace BSGraphics
{
    class State
    {
    public:
        void SetCameraData(const NiCamera* camera, unsigned flags);
    };

    class Renderer
    {
    public:
        void UpdateViewPort(unsigned first, unsigned second, bool enable);
        static void StartAccumulating(NiCamera* camera, BSShaderAccumulator* accumulator, unsigned flags);
        static void FinishAccumulatingPostResolveDepth(NiCamera* camera, BSShaderAccumulator* accumulator, unsigned flags);
        static void SubmitAccumulator(NiCamera* camera, BSShaderAccumulator* accumulator, unsigned flags);
    };

    extern State graphicsState;
    extern Renderer renderer;
    extern NiCamera* currentCamera;
}
