// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBooleanExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and storage: GUESS(low); extent observed on the target
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class CleanupBase9cf060
{
public:
    virtual ~CleanupBase9cf060();
    std::uint8_t unknown08[24];
};
class CleanupLeaf9cf060 : public CleanupBase9cf060
{
public:
    CleanupLeaf9cf060();
    ~CleanupLeaf9cf060() override;
};
