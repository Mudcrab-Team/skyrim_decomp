// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBase665230
{
public:
    virtual ~CleanupBase665230();
    std::uint8_t unknown08[32];
};
class CleanupLeaf665230 : public CleanupBase665230
{
public:
    CleanupLeaf665230();
    ~CleanupLeaf665230() override;
};
