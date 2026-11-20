// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered40bc50, object: GUESS(low) STANDIN
// Atmosphere: EXE_RTTI
// Source exposure: mixed (public complete data declarations and independent target root getter evidence).
// Code origin: public data declaration adaptation; root pointer offset8 independently recovered from RTTI-bound slot1 getter, no deletion-size inference.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/Atmosphere.h; MIT.
// Atmosphere: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered40bc50: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "LayoutValueTypes.h"
#include "SkyObjectRootStorageLayout.h"

namespace ResearchLayouts {
class BSFogProperty;
class BSTriShape;
class NiNode;
class F004Recovered40bc50 : public SkyObjectRootStorageLayout {
public:
    virtual ~F004Recovered40bc50();
    NiPointer<BSTriShape> atmosphere;
    NiPointer<BSFogProperty> fog;
    NiPointer<NiNode> skyQuadNode;
    NiPointer<BSTriShape> skyQuad;
    bool updateFogDistance;
};
static_assert(sizeof(F004Recovered40bc50) == 56, "community represented size");
static_assert(offsetof(F004Recovered40bc50, atmosphere) == 16, "atmosphere offset");
static_assert(offsetof(F004Recovered40bc50, fog) == 24, "fog offset");
static_assert(offsetof(F004Recovered40bc50, skyQuadNode) == 32, "skyQuadNode offset");
static_assert(offsetof(F004Recovered40bc50, skyQuad) == 40, "skyQuad offset");
static_assert(offsetof(F004Recovered40bc50, updateFogDistance) == 48, "updateFogDistance offset");
}
