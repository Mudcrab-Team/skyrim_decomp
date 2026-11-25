// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// BufferDestroyClearFreeWrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct BufferDestroyClearFreeWrappersVec3Ptr
{
    void* begin;
    void* end;
    void* cap;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void (*gFreeFn_3356370)(void* ptr);
extern "C" void DestroyRange_1264e70(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_1264ee0(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_1264f50(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_1264fd0(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_12650a0(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_12651b0(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_137bde0(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_1450310(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_1450380(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_1450410(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);
extern "C" void DestroyRange_1450490(void* begin, void* end, BufferDestroyClearFreeWrappersVec3Ptr* self);

struct BufferDestroyClearFreeWrappers
{
    static void Wrap1273b00(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap1273b50(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap1273be0(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap1273c30(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap1273d00(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap1273f60(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap137e850(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap1456200(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap14562d0(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap1456320(BufferDestroyClearFreeWrappersVec3Ptr* vec);
    static void Wrap14563f0(BufferDestroyClearFreeWrappersVec3Ptr* vec);
};
