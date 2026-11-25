// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBinaryExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
void ReleaseBinaryMemoryf0fcf0(void*);
class BinaryBasef0fcf0
{
public:
    virtual ~BinaryBasef0fcf0();
    std::uint8_t state[0x10];
};
class BinaryDtorLeaff0fcf0 : public BinaryBasef0fcf0
{
public:
    BinaryDtorLeaff0fcf0();
    ~BinaryDtorLeaff0fcf0() override;
    void* data;
    std::uint64_t unknown20;
};
