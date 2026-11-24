// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0xf1f050, 62 bytes: NiTriBasedGeomData scalar deleting destructor; the inline destructors chain to the out-of-line NiGeometryData destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0xf1f050 ??_GNiTriBasedGeomData@@UEAAPEAXI@Z
#include "NiTriBasedGeomData_f1f050.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
NiTriBasedGeomData::NiTriBasedGeomData()
{
}
