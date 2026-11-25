// Source exposure: mixed (pinned-image observations; community-generated names).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// RefAttachTechniqueInput, RefAttachTechniqueInput::SetAttachRoot: CRASHLOGGER_PDB(59818@2026.10.24)
// NiAVObject, AttachRootPointer, attachRoot, referenceCount: GUESS(low)
#pragma once
#include <cstddef>
#include <intrin.h>
struct NiAVObject;
struct NiAVObjectVtable {
    void* GetRTTI;
    void (*DeleteThis)(NiAVObject*);
};
struct NiAVObject {
    NiAVObjectVtable* vtable;
    volatile long referenceCount;  // volatile: shared reference count uses atomic interlocked updates.
};
struct AttachRootPointer {
    NiAVObject* pointer;
    explicit AttachRootPointer(NiAVObject* value) : pointer(value) {
        if (pointer)
            // Shared references require atomic updates.
            _InterlockedIncrement(&pointer->referenceCount);
    }
    ~AttachRootPointer() {
        if (pointer) {
            // Shared references require atomic updates.
            long count = _InterlockedDecrement(&pointer->referenceCount);
            if (count == 0)
                pointer->vtable->DeleteThis(pointer);
        }
    }
    AttachRootPointer& operator=(const AttachRootPointer& other) {
        auto previous = pointer;
        if (previous != other.pointer) {
            auto replacement = other.pointer;
            if (replacement)
                // Shared references require atomic updates.
            _InterlockedIncrement(&replacement->referenceCount);
            pointer = replacement;
            if (previous) {
                // Shared references require atomic updates.
            long count = _InterlockedDecrement(&previous->referenceCount);
                if (count == 0)
                    previous->vtable->DeleteThis(previous);
            }
        }
        return *this;
    }
};
struct RefAttachTechniqueInput {
    void* vtable;
    AttachRootPointer attachRoot;
    void SetAttachRoot(NiAVObject* value);
};
static_assert(offsetof(RefAttachTechniqueInput, attachRoot) == 8, "attach root offset");
