// Source exposure: mixed (local binary analysis and public names).
// Code origin: written for this reconstruction from the listing; names from public databases.
// Adapted bodies: none.
// BSInputDevice: EXE_RTTI
// IsEnabled: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
class BSIInputDevice
{
public:
    virtual ~BSIInputDevice();
};
// IsEnabled: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class BSInputDevice : public BSIInputDevice
{
public:
    ~BSInputDevice() {}
    virtual std::uint8_t IsEnabled() const;
    void Functione7c490();
};
