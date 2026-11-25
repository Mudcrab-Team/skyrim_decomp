// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTextKeyExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets and element size observed on the target.
#pragma once
#include <cstdint>
void operator delete[](void*, unsigned __int64) noexcept;
struct ArrayOwnerElementf88f50
{
    ~ArrayOwnerElementf88f50();
    std::uint32_t state[4];
};
class ArrayOwnerBasef88f50
{
public:
    virtual ~ArrayOwnerBasef88f50();
    std::uint8_t state[0x18];
};
class ArrayOwnerDtorLeaff88f50 : public ArrayOwnerBasef88f50
{
public:
    ~ArrayOwnerDtorLeaff88f50() override;
    ArrayOwnerElementf88f50* elements;
};
