// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// BufferClearFreeWrappers, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct BufferClearFreeWrappersVec3Ptr
{
    void* begin;
    void* end;
    void* cap;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" void (*gFreeFn_3356370)(void* ptr);

struct BufferClearFreeWrappers
{
    static void Wrap1273ba0(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap1274030(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap1274070(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap133c5b0(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap133c5f0(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap133c630(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap133c670(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap133c6b0(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap1348e40(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap137a1e0(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap13cd690(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap142b650(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap142b690(BufferClearFreeWrappersVec3Ptr* vec);
    static void Wrap146fd90(BufferClearFreeWrappersVec3Ptr* vec);
};
