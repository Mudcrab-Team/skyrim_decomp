// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered41cca0, object: GUESS(low) STANDIN
// Sun: EXE_RTTI
// Source exposure: mixed (public complete data declarations and independent target root getter evidence).
// Code origin: public data declaration adaptation; root pointer offset8 independently recovered from RTTI-bound slot1 getter, no deletion-size inference.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/Sun.h; MIT.
// Sun: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered41cca0: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "LayoutValueTypes.h"
#include "SkyObjectRootStorageLayout.h"

namespace ResearchLayouts {
class BSShaderAccumulator;
class BSTriShape;
class NiBillboardNode;
class NiDirectionalLight;
class F004Recovered41cca0 : public SkyObjectRootStorageLayout {
public:
    virtual ~F004Recovered41cca0();
    NiPointer<NiBillboardNode> sunBaseNode;
    NiPointer<NiBillboardNode> sunGlareNode;
    NiPointer<BSTriShape> sunBase;
    NiPointer<BSTriShape> sunQuery;
    NiPointer<BSTriShape> sunGlare;
    NiPointer<NiDirectionalLight> light;
    NiPointer<NiDirectionalLight> cloudLight;
    float glareScale;
    bool doOcclusionTests;
    NiPointer<BSShaderAccumulator> sunAccumulator;
};
static_assert(sizeof(F004Recovered41cca0) == 88, "community represented size");
static_assert(offsetof(F004Recovered41cca0, sunBaseNode) == 16, "sunBaseNode offset");
static_assert(offsetof(F004Recovered41cca0, sunGlareNode) == 24, "sunGlareNode offset");
static_assert(offsetof(F004Recovered41cca0, sunBase) == 32, "sunBase offset");
static_assert(offsetof(F004Recovered41cca0, sunQuery) == 40, "sunQuery offset");
static_assert(offsetof(F004Recovered41cca0, sunGlare) == 48, "sunGlare offset");
static_assert(offsetof(F004Recovered41cca0, light) == 56, "light offset");
static_assert(offsetof(F004Recovered41cca0, cloudLight) == 64, "cloudLight offset");
static_assert(offsetof(F004Recovered41cca0, glareScale) == 72, "glareScale offset");
static_assert(offsetof(F004Recovered41cca0, doOcclusionTests) == 76, "doOcclusionTests offset");
static_assert(offsetof(F004Recovered41cca0, sunAccumulator) == 80, "sunAccumulator offset");
}
