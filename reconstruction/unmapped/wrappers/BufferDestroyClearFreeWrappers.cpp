// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// BufferDestroyClearFreeWrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x1273b00 ?Wrap1273b00@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x1273b50 ?Wrap1273b50@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x1273be0 ?Wrap1273be0@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x1273c30 ?Wrap1273c30@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x1273d00 ?Wrap1273d00@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x1273f60 ?Wrap1273f60@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x137e850 ?Wrap137e850@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x1456200 ?Wrap1456200@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x14562d0 ?Wrap14562d0@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x1456320 ?Wrap1456320@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// CI hash: 0x14563f0 ?Wrap14563f0@BufferDestroyClearFreeWrappers@@SAXPEAUBufferDestroyClearFreeWrappersVec3Ptr@@@Z
// 0x1273b00 BufferDestroyClearFreeWrappers::Wrap1273b00
// 0x1273b50 BufferDestroyClearFreeWrappers::Wrap1273b50
// 0x1273be0 BufferDestroyClearFreeWrappers::Wrap1273be0
// 0x1273c30 BufferDestroyClearFreeWrappers::Wrap1273c30
// 0x1273d00 BufferDestroyClearFreeWrappers::Wrap1273d00
// 0x1273f60 BufferDestroyClearFreeWrappers::Wrap1273f60
// 0x137e850 BufferDestroyClearFreeWrappers::Wrap137e850
// 0x1456200 BufferDestroyClearFreeWrappers::Wrap1456200
// 0x14562d0 BufferDestroyClearFreeWrappers::Wrap14562d0
// 0x1456320 BufferDestroyClearFreeWrappers::Wrap1456320
// 0x14563f0 BufferDestroyClearFreeWrappers::Wrap14563f0
#include "BufferDestroyClearFreeWrappers.h"

void BufferDestroyClearFreeWrappers::Wrap1273b00(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1264e70(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap1273b50(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1264ee0(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap1273be0(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1264f50(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap1273c30(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1264fd0(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap1273d00(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_12650a0(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap1273f60(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_12651b0(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap137e850(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_137bde0(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap1456200(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1450310(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap14562d0(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1450380(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap1456320(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1450410(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}

void BufferDestroyClearFreeWrappers::Wrap14563f0(BufferDestroyClearFreeWrappersVec3Ptr* vec)
{
    void* ptr = vec->begin;
    if (ptr != nullptr)
    {
        DestroyRange_1450490(ptr, vec->end, vec);
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(vec->begin);
        }
        vec->begin = nullptr;
        vec->end = nullptr;
        vec->cap = nullptr;
    }
}
