// Source exposure: mixed (pinned image listing and public names).
// Code origin: existing leaf plus original reconstruction of Function44e3f0.
// Adapted bodies: none
// 0x44e300 BGSPackageDataLocationWrapper::Slot5
// 0x44e3f0 BGSPackageDataLocationWrapper::Function44e3f0
#include "BGSPackageDataLocationWrapper.h"

std::uint8_t BGSPackageDataLocationWrapper::Slot5() const
{
    return 0x1;
}

bool BGSPackageDataLocationWrapper::Function44e3f0(void*, void* a_arg)
{
    if (target) {
        return target->Slot5(a_arg);
    }
    return false;
}
