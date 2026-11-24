// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiControllerSequence: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// DeletingWrapperf42d60, storage: GUESS(low); stand-in for an observed object extent
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapperf42d60
{
public:
    virtual ~DeletingWrapperf42d60();
    std::uint8_t storage[176];
};
