// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf12500 IntegersCopyLeaff12500::CopyMembers
#include "IntegersCopyLeaff12500_f12500.h"

void IntegersCopyLeaff12500::CopyMembers(IntegersCopyLeaff12500* destination, IntegersCloneProcessf12500& process)
{
    IntegersCopyBasef12500::CopyMembers(destination, process);
    if (values && count) {
        destination->count = count;
        destination->values = static_cast<std::uint32_t*>(AllocateIntegersCopyf12500(static_cast<std::size_t>(count) * 4));
        for (std::uint32_t index = 0; index < count; ++index) {
            destination->values[index] = values[index];
        }
    } else {
        destination->values = nullptr;
        destination->count = 0;
    }
}
