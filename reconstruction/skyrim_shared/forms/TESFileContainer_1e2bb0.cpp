// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x1e2bb0 TESFileContainer::GetMaster
#include "TESFileContainer_1e2bb0.h"

// Return the first or last master file in the container's file array.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
TESFile1e2bb0* TESFileContainer::GetMaster(bool a_firstOnly) const
{
    TESFile1e2bb0* result = nullptr;
    if (array) {
        for (std::uint32_t i = 0; i < array->size; ++i) {
            TESFile1e2bb0* file = array->data[i];
            if (file && file->IsMaster()) {
                result = file;
                if (a_firstOnly) {
                    break;
                }
            }
        }
    }
    return result;
}
