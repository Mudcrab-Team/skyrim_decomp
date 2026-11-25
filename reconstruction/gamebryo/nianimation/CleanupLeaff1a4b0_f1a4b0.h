// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBasef1a4b0
{
public:
    virtual ~CleanupBasef1a4b0();
    std::uint8_t unknown08[32];
};
class CleanupLeaff1a4b0 : public CleanupBasef1a4b0
{
public:
    CleanupLeaff1a4b0();
    ~CleanupLeaff1a4b0() override;
};
