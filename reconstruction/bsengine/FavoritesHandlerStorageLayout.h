// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/F/FavoritesHandler.h; MIT.
// FavoritesHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// FavoritesHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/FavoritesHandlerLayout.h.
// FavoritesHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "MenuEventHandlerStorageLayout.h"

namespace ResearchLayouts {
class FavoritesHandlerStorageLayout : public MenuEventHandlerStorageLayout {
public:
    virtual ~FavoritesHandlerStorageLayout();
};
static_assert(sizeof(FavoritesHandlerStorageLayout) == 16, "community represented size");
}
