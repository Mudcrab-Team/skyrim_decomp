// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// ThirdPersonState, ThirdPersonState::sub_14084F780: CRASHLOGGER_PDB(59818@2026.10.24)
// gDefaultZoomOffset, unk00, savedPosX, savedPosY, savedPosZ, posX, posY, posZ, currentZoomOffset, targetZoomOffset, unk7C, savedZoomOffset: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

extern float gDefaultZoomOffset;

class ThirdPersonState
{
public:
    void sub_14084F780(bool a_keepCurrentZoom, bool a_resetSavedZoom);

    std::uint8_t unk00[0x5C];
    float savedPosX;
    float savedPosY;
    float savedPosZ;
    float posX;
    float posY;
    float posZ;
    float currentZoomOffset;
    float targetZoomOffset;
    std::uint8_t unk7C[0x8];
    float savedZoomOffset;
};

static_assert(offsetof(ThirdPersonState, savedPosX) == 0x5C, "savedPosX offset");
static_assert(offsetof(ThirdPersonState, posX) == 0x68, "posX offset");
static_assert(offsetof(ThirdPersonState, currentZoomOffset) == 0x74, "currentZoomOffset offset");
static_assert(offsetof(ThirdPersonState, targetZoomOffset) == 0x78, "targetZoomOffset offset");
static_assert(offsetof(ThirdPersonState, savedZoomOffset) == 0x84, "savedZoomOffset offset");
