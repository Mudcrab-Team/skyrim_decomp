// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports BSMultiBound::RegisterStreamables as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niconsolerenderer/niconsolepersistentsrctexturerendererdata_od_variant_ob1_variant.cpp:49
// SPDX-License-Identifier: CC0-1.0
// BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBound::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfcd740 BSMultiBound::RegisterStreamables
#include "BSMultiBound_fcd740.h"

// Register the bound and its shape with the stream.
bool BSMultiBound::RegisterStreamables(NiStream& a_stream)
{
    if (!NiObject::RegisterStreamables(a_stream)) {
        return false;
    }

    data->RegisterStreamables(a_stream);
    return true;
}
