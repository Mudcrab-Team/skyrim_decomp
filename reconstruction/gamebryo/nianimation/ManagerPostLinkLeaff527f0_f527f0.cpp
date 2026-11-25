// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf527f0 ManagerPostLinkLeaff527f0::PostLinkObject
#include "ManagerPostLinkLeaff527f0_f527f0.h"

void ManagerPostLinkLeaff527f0::PostLinkObject(ManagerStream& stream)
{
    ManagerPostLinkBase::PostLinkObject(stream);
    auto* targetObject = target;
    for (std::uint32_t index = 0; index < count; ++index) {
        if (sequences[index]) {
            sequences[index]->SetTarget(targetObject);
        }
    }
}
