// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xef6c60 BSDismemberSkinInstance::Functionef6c60
// Adapted bodies: none
#include "BSDismemberSkinInstance_ef6c60.h"

void BSDismemberSkinInstance::Functionef6c60(void* buffer, std::uint32_t count)
{
    // the element size reuses the count parameter's slot once the byte total is taken
    const std::uint32_t totalBytes = count * 4;
    count = 4;
    position += io(this, buffer, totalBytes, &count, 1);
}
