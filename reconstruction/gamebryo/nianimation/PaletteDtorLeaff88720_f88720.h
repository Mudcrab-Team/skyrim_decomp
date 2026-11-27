// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiStringPalette: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
void ReleasePaletteMemoryf88720(void*);
// volatile: the target updates this counter atomically.
extern volatile long gPaletteCountf88720;
class PaletteDtorBasef88720
{
public:
    virtual ~PaletteDtorBasef88720();
    std::uint64_t state;
};
class PaletteDtorLeaff88720 : public PaletteDtorBasef88720
{
public:
    PaletteDtorLeaff88720();
    ~PaletteDtorLeaff88720() override;
    void* data;
    std::uint64_t unknown18;
};
