// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiIntegersExtraData, CopyMembers: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstddef>
#include <cstdint>
void* AllocateIntegersCopyf12500(std::size_t size);
struct IntegersCloneProcessf12500;
struct IntegersCopyBasef12500
{
    void CopyMembers(IntegersCopyBasef12500* destination, IntegersCloneProcessf12500& process);
    std::uint8_t state[0x18];
};
struct IntegersCopyLeaff12500 : IntegersCopyBasef12500
{
    void CopyMembers(IntegersCopyLeaff12500* destination, IntegersCloneProcessf12500& process);
    std::uint32_t count;
    std::uint32_t* values;
};
