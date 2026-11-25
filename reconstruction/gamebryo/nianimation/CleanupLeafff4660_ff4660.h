// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBaseff4660
{
public:
    virtual ~CleanupBaseff4660();
    std::uint8_t unknown08[32];
};
class CleanupLeafff4660 : public CleanupBaseff4660
{
public:
    CleanupLeafff4660();
    ~CleanupLeafff4660() override;
};
