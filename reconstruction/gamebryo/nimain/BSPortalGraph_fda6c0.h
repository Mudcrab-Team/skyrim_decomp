// Source exposure: mixed (pinned image and public declarations).
// Code origin: original portal graph prefix from the always-render traversal and cache lookup.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSPortalGraph, BSPortalGraphEntry, BSFixedString, NiAVObject, alwaysRenderChildren, cellID: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// FindAlwaysRenderBone, GetAlwaysRenderChild, MatchesEntry, PortalGraphCacheKey: GUESS(low)
#pragma once

#include <cstdint>

class BSFixedString;
class BSPortalGraph;

class NiAVObject
{
public:
    static NiAVObject* GetBoneFromName(NiAVObject* root, const BSFixedString& name, bool recurse);
};

struct PortalGraphCacheKey
{
    std::uint8_t unknown00[0x10];
    const BSPortalGraph* portalGraph;
    std::uint8_t unknown18[0x120];
    std::uint32_t cellID;
};

class BSPortalGraph
{
public:
    NiAVObject* GetAlwaysRenderChild(std::uint32_t index) const;
    NiAVObject* FindAlwaysRenderBone(const BSFixedString& name) const;
    bool MatchesEntry(const PortalGraphCacheKey& entry) const;

private:
    std::uint8_t unknown00[0x58];
    struct {
        NiAVObject** data;
        std::uint8_t unknown08[8];
        std::uint32_t size;
        std::uint32_t unknown14;
    } alwaysRenderChildren;
    std::uint8_t unknown70[0x50];
    std::uint32_t cellID;
};
