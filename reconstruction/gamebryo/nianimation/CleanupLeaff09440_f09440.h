// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiKeyBasedInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBasef09440
{
public:
    virtual ~CleanupBasef09440();
    std::uint8_t unknown08[16];
};
class CleanupLeaff09440 : public CleanupBasef09440
{
public:
    CleanupLeaff09440();
    ~CleanupLeaff09440() override;
};
