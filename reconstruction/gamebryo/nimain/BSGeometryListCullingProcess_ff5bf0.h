// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSGeometryListCullingProcess, AppendNonAccum, lightIndex and objectArray: CRASHLOGGER_PDB(59818@2026.10.24)
// ArrayAllocator, ArraySize, ObjectArray, LightProperty, SetLightIndex and associated interfaces: GUESS(low) STANDIN
// IAllocatorFunctor, Allocate, Reallocate and Deallocate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

struct LightProperty;
struct LightPropertyMethods {
    void* preceding[41];
    void (*SetLightIndex)(LightProperty*, int);
};
struct LightProperty { LightPropertyMethods* methods; };
struct NiAVObject {
    void* vtable;
    long refCount;
    unsigned char unknown0C[0x11C];
    LightProperty* property;
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
    unsigned int AppendIndex(ArrayAllocator& allocator, unsigned int capacity, unsigned int elementSize);
};

struct ObjectArray {
    NiAVObject** data;
    unsigned int capacity;
    unsigned int padding;
    ArraySize count;
    void Append(NiAVObject* object);
};

struct BSGeometryListCullingProcess {
    unsigned char unknown00[0x128];
    ObjectArray objectArray;
    unsigned char unknown140[0x300B8];
    int lightIndex;
    void AppendNonAccum(NiAVObject* object);
};
