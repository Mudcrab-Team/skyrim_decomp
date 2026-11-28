// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0xd068f0 ResourceKey_d068f0::ResourceKey_d068f0
// Adapted bodies: none
#include "ResourceKey_d068f0.h"

// Copy-constructs a resource key and increments the key interface's reference count when present.
// The community name table calls this Scaleform::GFx::ResourceKey::ResourceKey (a hint, not proof); the names in this unit are stand-ins.
ResourceKey_d068f0::ResourceKey_d068f0(const ResourceKey_d068f0& a_other)
{
    if (a_other.keyInterface) {
        a_other.keyInterface->AddRef(a_other.keyData);
    }
    keyInterface = a_other.keyInterface;
    keyData = a_other.keyData;
}
