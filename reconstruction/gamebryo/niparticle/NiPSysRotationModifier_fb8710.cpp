// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xfb8710 NiPSysRotationModifier::CopyMembers
#include "NiPSysRotationModifier_fb8710.h"

// Copies base modifier members and rotation parameters into the destination modifier.
void NiPSysRotationModifier::CopyMembers(NiPSysRotationModifier* a_dest, NiCloningProcess& a_clone)
{
    NiPSysModifier::CopyMembers(a_dest, a_clone);
    a_dest->rotationSpeed = rotationSpeed;
    a_dest->rotationSpeedVar = rotationSpeedVar;
    a_dest->randomRotSpeedSign = randomRotSpeedSign;
    a_dest->rotationAngle = rotationAngle;
    a_dest->rotationAngleVar = rotationAngleVar;
    a_dest->randomAxis = randomAxis;
    a_dest->axisX = axisX;
    a_dest->axisY = axisY;
    a_dest->axisZ = axisZ;
}
