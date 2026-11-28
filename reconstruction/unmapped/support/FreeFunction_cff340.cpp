// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xcff340 Functioncff340
// Adapted bodies: none
#include "FreeFunction_cff340.h"

// Resizes buffer to newSize, growing capacity on a growSize boundary and null-terminating the buffer.
// The community name table calls this Scaleform::StringBuffer::Resize (a hint, not proof); the names in this unit are stand-ins.
void Functioncff340(StringBuffercff340* buffer, std::size_t newSize)
{
    if (newSize >= buffer->capacity) {
        buffer->capacity = (newSize + buffer->growSize) & ~(buffer->growSize - 1);
        if (buffer->data == nullptr) {
            buffer->data = buffer->heap->Alloc(buffer->capacity, nullptr);
        } else {
            buffer->data = g_globalHeapcff340->Realloc(buffer->data, buffer->capacity);
        }
    }
    buffer->lengthIsSize = false;
    buffer->size = newSize;
    if (buffer->data != nullptr) {
        buffer->data[newSize] = 0;
    }
}
