// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of always-render child lookup and graph identity.
// 0xfda6c0 BSPortalGraph::GetAlwaysRenderChild
// 0xfda6f0 BSPortalGraph::FindAlwaysRenderBone
// 0xfdadb0 BSPortalGraph::MatchesEntry
#include "BSPortalGraph_fda6c0.h"

NiAVObject* BSPortalGraph::GetAlwaysRenderChild(std::uint32_t index) const
{
    return alwaysRenderChildren.data[index];
}

NiAVObject* BSPortalGraph::FindAlwaysRenderBone(const BSFixedString& name) const
{
    NiAVObject* result = nullptr;
    std::uint32_t index = 0;
    do {
        if (index >= alwaysRenderChildren.size) {
            break;
        }
        result = NiAVObject::GetBoneFromName(alwaysRenderChildren.data[index++], name, true);
    } while (result == nullptr);
    return result;
}

bool BSPortalGraph::MatchesEntry(const PortalGraphCacheKey& entry) const
{
    return this == entry.portalGraph && cellID == entry.cellID;
}
