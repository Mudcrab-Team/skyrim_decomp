// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSGeometryListCullingProcess, ReserveObjectArray and objectArray: CRASHLOGGER_PDB(59818@2026.10.24)
// ArrayAllocator, ObjectArrayAllocator, ArraySize and ObjectArray: GUESS(low) STANDIN
// IAllocatorFunctor, Allocate, Reallocate and Deallocate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

struct NiAVObject {
    void* vtable;
    long refCount;
};
struct ObjectArray;
struct ArrayAllocator {
    virtual bool Allocate(unsigned int count, unsigned int elementSize) = 0;
    virtual bool Reallocate(unsigned int capacity, unsigned int front, unsigned int shift,
                            unsigned int back, unsigned int elementSize) = 0;
    virtual void Deallocate() = 0;
    virtual ~ArrayAllocator() {}
};
struct ObjectArrayAllocator : ArrayAllocator {
    explicit ObjectArrayAllocator(ObjectArray& owner) : array(&owner) {}
    bool Allocate(unsigned int count, unsigned int elementSize) override;
    bool Reallocate(unsigned int capacity, unsigned int front, unsigned int shift,
                    unsigned int back, unsigned int elementSize) override;
    void Deallocate() override;
    ~ObjectArrayAllocator() override {}
    ObjectArray* array;
};

struct ArraySize {
    unsigned int size;
    void Reserve(ArrayAllocator& allocator, unsigned int capacity, unsigned int requested, unsigned int elementSize);
};

struct ObjectArray {
    NiAVObject** data;
    unsigned int capacity;
    unsigned int padding;
    ArraySize count;
    void Reserve(unsigned int requested);
};

struct BSGeometryListCullingProcess {
    unsigned char unknown00[0x128];
    ObjectArray objectArray;
    void ReserveObjectArray();
};
