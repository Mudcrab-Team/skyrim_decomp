// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSInputDeviceManager, BSInputDeviceManager::GetButtonNameFromID: CRASHLOGGER_PDB(59818@2026.10.24)
// BSIInputDevice, BSFixedString, GetKeyMapping, devices: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct BSFixedString;

class BSIInputDevice
{
public:
    virtual ~BSIInputDevice();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual bool GetKeyMapping(std::uint32_t a_key, BSFixedString& a_out) const;
};

class BSInputDeviceManager
{
public:
    bool GetButtonNameFromID(std::int32_t a_device, std::uint32_t a_id, BSFixedString& a_out) const;

    std::uint8_t unk00[0x60];
    BSIInputDevice* devices[4];
};

static_assert(offsetof(BSInputDeviceManager, devices) == 0x60, "devices offset");
