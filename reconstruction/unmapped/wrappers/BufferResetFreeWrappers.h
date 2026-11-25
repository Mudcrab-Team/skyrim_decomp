// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// BufferResetFreeWrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct BufferResetFreeWrappersVecBuf1
{
    unsigned char* begin;
    unsigned char* end;
    unsigned char* cap;
};

struct BufferResetFreeWrappersVecBuf2
{
    unsigned short* begin;
    unsigned short* end;
    unsigned short* cap;
};

struct BufferResetFreeWrappersVecBuf4
{
    unsigned int* begin;
    unsigned int* end;
    unsigned int* cap;
};

struct BufferResetFreeWrappersVecBuf8
{
    unsigned long long* begin;
    unsigned long long* end;
    unsigned long long* cap;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void (*gFreeFn_3356370)(void* ptr);

struct BufferResetFreeWrappers
{
    static void Wrap12738b0(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap1285160(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap12851d0(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap128d780(BufferResetFreeWrappersVecBuf1* vec, unsigned char* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap12b9110(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap12f0d00(BufferResetFreeWrappersVecBuf1* vec, unsigned char* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap1301200(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap1318b10(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap1342f10(BufferResetFreeWrappersVecBuf2* vec, unsigned short* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap1348950(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap139b1f0(BufferResetFreeWrappersVecBuf2* vec, unsigned short* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap13a01b0(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap13ac030(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap14027d0(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap1411d30(BufferResetFreeWrappersVecBuf4* vec, unsigned int* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap142af60(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
    static void Wrap143b210(BufferResetFreeWrappersVecBuf8* vec, unsigned long long* newBuf, unsigned long long newSize, unsigned long long newCap);
};
