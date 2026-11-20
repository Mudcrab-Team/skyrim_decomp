// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered3f9250, object: GUESS(low) STANDIN
// bhkAction: EXE_RTTI
// Source exposure: community-headers
// Code origin: adapted public base declaration only; no implementation body reused.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/bhkAction.h; GPL-3.0.
// SPDX-License-Identifier: GPL-3.0-only
// bhkAction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// F004Recovered3f9250: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
#include "BhkSerializableLayout.h"
namespace ResearchLayouts {
class F004Recovered3f9250 : public BhkSerializableLayout {
public:
    ~F004Recovered3f9250() override;
};
static_assert(sizeof(F004Recovered3f9250)==32,"public fieldless ancestry size");
static_assert(offsetof(F004Recovered3f9250,referencedObject)==16,"public inherited hkRefPtr offset");
static_assert(offsetof(F004Recovered3f9250,serializable)==24,"public inherited serialization pointer offset");
}
