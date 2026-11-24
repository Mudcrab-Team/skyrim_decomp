// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// MarketplaceBundleContent, MarketplaceContent: EXE_RTTI
// MarketplaceContent: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class MarketplaceContent
{
public:
    MarketplaceContent();
    virtual ~MarketplaceContent();
};

class MarketplaceBundleContent : public MarketplaceContent
{
public:
    MarketplaceBundleContent();
    ~MarketplaceBundleContent() override {}

    char unk08[0xF8];
};
static_assert(sizeof(MarketplaceBundleContent) == 0x100, "MarketplaceBundleContent size from the deleting destructor");
