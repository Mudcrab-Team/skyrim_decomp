// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/N/NeedToUpdateCreationClubCallback.h; GPL-3.0.
// NeedToUpdateCreationClubCallback: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NeedToUpdateCreationClubCallbackLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/NeedToUpdateCreationClubCallbackLayout.h.
// NeedToUpdateCreationClubCallbackStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "IMessageBoxCallbackStorageLayout.h"

namespace ResearchLayouts {
class NeedToUpdateCreationClubCallbackStorageLayout : public IMessageBoxCallbackStorageLayout {
public:
    virtual ~NeedToUpdateCreationClubCallbackStorageLayout();
};
static_assert(sizeof(NeedToUpdateCreationClubCallbackStorageLayout) == 16, "community represented size");
}
