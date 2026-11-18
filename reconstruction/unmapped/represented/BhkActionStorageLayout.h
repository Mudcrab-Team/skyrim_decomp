// Source exposure: community-headers
// Code origin: adapted public base declaration only; no implementation body reused.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/bhkAction.h; GPL-3.0.
// SPDX-License-Identifier: GPL-3.0-only
// bhkAction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BhkActionStorageLayout: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
#include "BhkSerializableLayout.h"
namespace ResearchLayouts {
class BhkActionStorageLayout : public BhkSerializableLayout {
public:
    ~BhkActionStorageLayout() override;
};
static_assert(sizeof(BhkActionStorageLayout)==32,"public fieldless ancestry size");
static_assert(offsetof(BhkActionStorageLayout,referencedObject)==16,"public inherited hkRefPtr offset");
static_assert(offsetof(BhkActionStorageLayout,serializable)==24,"public inherited serialization pointer offset");
}
