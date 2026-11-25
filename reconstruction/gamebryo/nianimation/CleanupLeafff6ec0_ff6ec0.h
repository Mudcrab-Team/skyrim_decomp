// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBooleanExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBaseff6ec0
{
public:
    virtual ~CleanupBaseff6ec0();
    std::uint8_t unknown08[24];
};
class CleanupLeafff6ec0 : public CleanupBaseff6ec0
{
public:
    CleanupLeafff6ec0();
    ~CleanupLeafff6ec0() override;
};
