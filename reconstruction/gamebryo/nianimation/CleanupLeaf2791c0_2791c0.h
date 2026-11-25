// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBooleanExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBase2791c0
{
public:
    virtual ~CleanupBase2791c0();
    std::uint8_t unknown08[24];
};
class CleanupLeaf2791c0 : public CleanupBase2791c0
{
public:
    CleanupLeaf2791c0();
    ~CleanupLeaf2791c0() override;
};
