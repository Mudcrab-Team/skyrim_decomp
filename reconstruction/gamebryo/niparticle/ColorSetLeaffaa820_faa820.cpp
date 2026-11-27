// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfaa820 ColorSetLeaffaa820::SetColorData
#include "ColorSetLeaffaa820_faa820.h"
#include <intrin.h>

void ColorSetLeaffaa820::SetColorData(ColorSetDatafaa820* replacement)
{
    auto* old = data;
    if (old != replacement) {
        if (replacement) {
            // Increment the new reference count atomically.
            _InterlockedIncrement(&replacement->count);
        }
        data = replacement;
        if (old) {
            // Decrement the previous reference count atomically.
    // The reference-object counter is updated atomically.
            if (_InterlockedDecrement(&old->count) == 0) {
                old->table->destroy(old);
            }
        }
    }
    firstTime = 0;
    lastTime = 0;
    auto* current = data;
    if (current) {
        std::uint32_t count = current->keyCount;
        std::uint8_t stride = current->stride;
        std::uint8_t* keys = current->keys;
        if (count) {
            firstTime = *reinterpret_cast<std::uint32_t*>(keys);
            lastTime = *reinterpret_cast<std::uint32_t*>(keys + (count - 1) * stride);
        }
    }
}
