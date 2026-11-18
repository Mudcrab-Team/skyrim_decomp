// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/N/NeedToUpdateCreationClubCallback.h; GPL-3.0.
// NeedToUpdateCreationClubCallback: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NeedToUpdateCreationClubCallbackLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/interface/IMessageBoxCallbackLayout.h"

namespace ResearchLayouts {
class NeedToUpdateCreationClubCallbackLayout : public IMessageBoxCallbackLayout {
public:
    virtual ~NeedToUpdateCreationClubCallbackLayout();
};
static_assert(sizeof(NeedToUpdateCreationClubCallbackLayout) == 16, "community represented size");
}
