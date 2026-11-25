// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBase1004f30
{
public:
    virtual ~CleanupBase1004f30();
    std::uint8_t unknown08[32];
};
class CleanupLeaf1004f30 : public CleanupBase1004f30
{
public:
    CleanupLeaf1004f30();
    ~CleanupLeaf1004f30() override;
};
