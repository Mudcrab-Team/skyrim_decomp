// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing: vtable store then tail call to base destructor.
// 0xe7c490 BSInputDevice::Functione7c490
// Adapted bodies: none.
// 0xcfc170 BSInputDevice::IsEnabled
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "BSInputDevice.h"

// IsEnabled: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t BSInputDevice::IsEnabled() const
{
    return 0x1;
}

void BSInputDevice::Functione7c490()
{
    this->BSInputDevice::~BSInputDevice();
}
