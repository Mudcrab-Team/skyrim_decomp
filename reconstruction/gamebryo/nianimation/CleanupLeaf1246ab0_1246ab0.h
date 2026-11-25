// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBooleanExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBase1246ab0
{
public:
    virtual ~CleanupBase1246ab0();
    std::uint8_t unknown08[24];
};
class CleanupLeaf1246ab0 : public CleanupBase1246ab0
{
public:
    CleanupLeaf1246ab0();
    ~CleanupLeaf1246ab0() override;
};
