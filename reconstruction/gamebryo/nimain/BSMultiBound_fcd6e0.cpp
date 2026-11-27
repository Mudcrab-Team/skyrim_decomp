// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiRefObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:15
// SPDX-License-Identifier: CC0-1.0
// BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBound::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfcd6e0 BSMultiBound::LinkObject
#include "BSMultiBound_fcd6e0.h"

// Link the base object and resolve the bound shape reference from the stream.
void BSMultiBound::LinkObject(NiStream& a_stream)
{
    NiObject::LinkObject(a_stream);
    data = static_cast<BSMultiBoundShape*>(a_stream.ReadLinkID());
}
