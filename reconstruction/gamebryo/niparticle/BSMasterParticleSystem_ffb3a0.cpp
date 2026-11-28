// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: SaveStreamValue, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// 0xffb3a0 BSMasterParticleSystem::SaveBinary_140D5DE00
#include "BSMasterParticleSystem_ffb3a0.h"

namespace
{
    template <class T>
    void SaveStreamValue(NiBinaryStream& a_stream, const T& a_value)
    {
        std::uint32_t componentSize = sizeof(T);
        std::uint32_t written = a_stream.writeFn(&a_stream, &a_value, sizeof(T), &componentSize, 1);
        a_stream.absoluteCurrentPos += written;
    }
}

void BSMasterParticleSystem::SaveBinary_140D5DE00(NiStream& a_stream)
{
    NiNode::SaveBinary(a_stream);
    SaveStreamValue(*a_stream.binaryStream, maxEmitterObj);
    std::uint32_t count = particlesCount;
    SaveStreamValue(*a_stream.binaryStream, count);
    for (std::uint32_t i = 0; i < count; ++i) {
        a_stream.SaveLinkID(particlesData[i]);
    }
}
