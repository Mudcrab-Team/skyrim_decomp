// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiCollisionObject: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiCollisionObject::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x156ada0 NiCollisionObject::LinkObject
#include "NiCollisionObject_156ada0.h"

// Link base object data and resolve the target scene object from the stream.
void NiCollisionObject::LinkObject(NiStream& a_stream)
{
    NiObject::LinkObject(a_stream);
    sceneObject = a_stream.ReadLinkID();
}
