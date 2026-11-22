// Source exposure: mixed (pinned image listing and labelled declarations).
// Code origin: original reconstruction from the pinned listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BGSPackageDataLocationWrapper::LoadGame: CRASHLOGGER_PDB(59818@2026.10.24)
// ReadPackageLocation, loadedLocation: GUESS(low)
// 0x44e300 BGSPackageDataLocationWrapper::Slot5
// 0x44e3f0 BGSPackageDataLocationWrapper::Function44e3f0
// 0x44e330 BGSPackageDataLocationWrapper::LoadGame
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

// Restore the package location from the saved game data.
void BGSPackageDataLocationWrapper::LoadGame(BGSLoadGameBuffer& a_buffer)
{
    loadedLocation = ReadPackageLocation(a_buffer);
}
