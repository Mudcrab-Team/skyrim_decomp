// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xff5bf0 BSGeometryListCullingProcess::AppendNonAccum
#include "BSGeometryListCullingProcess_ff5bf0.h"

#include <intrin.h>


inline void ObjectArray::Append(NiAVObject* object)
{
    unsigned int index;
    {
        ObjectArrayAllocator allocator(*this);
        index = count.AppendIndex(allocator, capacity, sizeof(object));
    }
    if (index != static_cast<unsigned int>(-1)) {
        data[index] = object;
        if (object) {
            // Other culling workers can retain the same object concurrently.
            _InterlockedIncrement(&object->refCount);
        }
    }
}

void BSGeometryListCullingProcess::AppendNonAccum(NiAVObject* object)
{
    objectArray.Append(object);
    if (lightIndex)
        object->property->methods->SetLightIndex(object->property, lightIndex);
}
