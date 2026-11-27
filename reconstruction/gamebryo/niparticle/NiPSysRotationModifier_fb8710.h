// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// NiPSysRotationModifier, NiPSysRotationModifier::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCloningProcess, NiPSysModifier, NiPSysModifier::CopyMembers, unk00, rotationSpeed, rotationSpeedVar, rotationAngle, rotationAngleVar, axisX, axisY, axisZ, randomAxis, randomRotSpeedSign: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiCloningProcess;

class NiPSysModifier
{
public:
    void CopyMembers(NiPSysModifier* a_dest, NiCloningProcess& a_clone);

    std::uint8_t unk00[0x30];
};

class NiPSysRotationModifier : public NiPSysModifier
{
public:
    void CopyMembers(NiPSysRotationModifier* a_dest, NiCloningProcess& a_clone);

    float rotationSpeed;
    float rotationSpeedVar;
    float rotationAngle;
    float rotationAngleVar;
    float axisX;
    float axisY;
    float axisZ;
    bool randomAxis;
    bool randomRotSpeedSign;
};

static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");
static_assert(offsetof(NiPSysRotationModifier, randomAxis) == 0x4C, "randomAxis offset");
static_assert(offsetof(NiPSysRotationModifier, randomRotSpeedSign) == 0x4D, "randomRotSpeedSign offset");
