// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// BufferResetFreeWrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x12738b0 ?Wrap12738b0@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x1285160 ?Wrap1285160@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x12851d0 ?Wrap12851d0@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x128d780 ?Wrap128d780@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf1@@PEAE_K2@Z
// CI hash: 0x12b9110 ?Wrap12b9110@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x12f0d00 ?Wrap12f0d00@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf1@@PEAE_K2@Z
// CI hash: 0x1301200 ?Wrap1301200@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x1318b10 ?Wrap1318b10@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf4@@PEAI_K2@Z
// CI hash: 0x1342f10 ?Wrap1342f10@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf2@@PEAG_K2@Z
// CI hash: 0x1348950 ?Wrap1348950@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf4@@PEAI_K2@Z
// CI hash: 0x139b1f0 ?Wrap139b1f0@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf2@@PEAG_K2@Z
// CI hash: 0x13a01b0 ?Wrap13a01b0@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x13ac030 ?Wrap13ac030@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x14027d0 ?Wrap14027d0@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf4@@PEAI_K2@Z
// CI hash: 0x1411d30 ?Wrap1411d30@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf4@@PEAI_K2@Z
// CI hash: 0x142af60 ?Wrap142af60@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// CI hash: 0x143b210 ?Wrap143b210@BufferResetFreeWrappers@@SAXPEAUBufferResetFreeWrappersVecBuf8@@PEA_K_K2@Z
// 0x12738b0 BufferResetFreeWrappers::Wrap12738b0
// 0x1285160 BufferResetFreeWrappers::Wrap1285160
// 0x12851d0 BufferResetFreeWrappers::Wrap12851d0
// 0x128d780 BufferResetFreeWrappers::Wrap128d780
// 0x12b9110 BufferResetFreeWrappers::Wrap12b9110
// 0x12f0d00 BufferResetFreeWrappers::Wrap12f0d00
// 0x1301200 BufferResetFreeWrappers::Wrap1301200
// 0x1318b10 BufferResetFreeWrappers::Wrap1318b10
// 0x1342f10 BufferResetFreeWrappers::Wrap1342f10
// 0x1348950 BufferResetFreeWrappers::Wrap1348950
// 0x139b1f0 BufferResetFreeWrappers::Wrap139b1f0
// 0x13a01b0 BufferResetFreeWrappers::Wrap13a01b0
// 0x13ac030 BufferResetFreeWrappers::Wrap13ac030
// 0x14027d0 BufferResetFreeWrappers::Wrap14027d0
// 0x1411d30 BufferResetFreeWrappers::Wrap1411d30
// 0x142af60 BufferResetFreeWrappers::Wrap142af60
// 0x143b210 BufferResetFreeWrappers::Wrap143b210
#include "BufferResetFreeWrappers.h"

void BufferResetFreeWrappers::Wrap12738b0(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap1285160(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap12851d0(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap128d780(BufferResetFreeWrappersVecBuf1* vec, unsigned char* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned char* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap12b9110(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap12f0d00(BufferResetFreeWrappersVecBuf1* vec, unsigned char* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned char* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap1301200(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap1318b10(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned int* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap1342f10(BufferResetFreeWrappersVecBuf2* vec, unsigned short* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned short* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap1348950(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned int* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap139b1f0(BufferResetFreeWrappersVecBuf2* vec, unsigned short* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned short* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap13a01b0(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap13ac030(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap14027d0(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned int* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap1411d30(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned int* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap142af60(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}

void BufferResetFreeWrappers::Wrap143b210(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap)
{
    unsigned long long* cur = vec->begin;
    if (cur != nullptr)
    {
        if (gAllocFn_3356368 != nullptr && gFreeFn_3356370 != nullptr)
        {
            gFreeFn_3356370(cur);
        }
    }
    vec->begin = newBuf;
    vec->end = newBuf + newSize;
    vec->cap = newBuf + newCap;
}
