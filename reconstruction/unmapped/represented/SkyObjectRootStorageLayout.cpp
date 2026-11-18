// Source exposure: mixed (public complete data declarations and independent target root getter evidence).
// Code origin: public data declaration adaptation; root pointer offset8 independently recovered from RTTI-bound slot1 getter, no deletion-size inference.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/SkyObject.h; MIT.
// SkyObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SkyObjectRootStorageLayout: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetRoot: GUESS(medium); implementation reconstructed from the bound target pointer load, public method slot1 supplies a name candidate.
// 0x41a200 represented SkyObject root pointer getter
#include "SkyObjectRootStorageLayout.h"
namespace ResearchLayouts {
NiNode* SkyObjectRootStorageLayout::GetRoot() { return root.value; }
}
