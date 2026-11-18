// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered7695f0, object: GUESS(low) STANDIN
// bhkMouseSpringAction: EXE_RTTI
// Source exposure: community-headers
// Code origin: adapted public base declaration only; no implementation body reused.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/bhkMouseSpringAction.h; GPL-3.0.
// SPDX-License-Identifier: GPL-3.0-only
// bhkMouseSpringAction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// F004Recovered7695f0: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
#include "BhkUnaryActionStorageLayout.h"
namespace ResearchLayouts {
class F004Recovered7695f0 : public BhkUnaryActionStorageLayout {
public:
    ~F004Recovered7695f0() override;
};
static_assert(sizeof(F004Recovered7695f0)==32,"public fieldless ancestry size");
static_assert(offsetof(F004Recovered7695f0,referencedObject)==16,"public inherited hkRefPtr offset");
static_assert(offsetof(F004Recovered7695f0,serializable)==24,"public inherited serialization pointer offset");
}
