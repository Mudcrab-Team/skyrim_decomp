// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xef6dd0 BSDismemberSkinInstance::Functionef6dd0
// Adapted bodies: none
#include "BSDismemberSkinInstance_ef6dd0.h"

void BSDismemberSkinInstance::Functionef6dd0(void* buffer, std::uint32_t count)
{
    // the element size reuses the count parameter's slot once the byte total is taken
    BinaryStreamLike* target = forwardTarget;
    const std::uint32_t totalBytes = count * 4;
    count = 4;
    target->position += target->io(target, buffer, totalBytes, &count, 1);
}
