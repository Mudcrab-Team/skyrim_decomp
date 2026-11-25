// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiKeyBasedInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBase7a6de0
{
public:
    virtual ~CleanupBase7a6de0();
    std::uint8_t unknown08[16];
};
class CleanupLeaf7a6de0 : public CleanupBase7a6de0
{
public:
    CleanupLeaf7a6de0();
    ~CleanupLeaf7a6de0() override;
};
