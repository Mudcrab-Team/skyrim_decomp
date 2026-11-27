// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTSmallArrayEraseOrdered, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstdint>

struct BSTSmallArray_8 {
    std::int32_t capacity;
    union {
        void* heapData;
        std::uint8_t localData[8];
    };
    std::uint32_t size;
    void* Data() {
        return (capacity < 0) ? static_cast<void*>(localData) : heapData;
    }
};

struct BSTSmallArray_16 {
    std::int32_t capacity;
    union {
        void* heapData;
        std::uint8_t localData[16];
    };
    std::uint32_t size;
    void* Data() {
        return (capacity < 0) ? static_cast<void*>(localData) : heapData;
    }
};

struct BSTSmallArray_24 {
    std::int32_t capacity;
    union {
        void* heapData;
        std::uint8_t localData[24];
    };
    std::uint32_t size;
    void* Data() {
        return (capacity < 0) ? static_cast<void*>(localData) : heapData;
    }
};

struct BSTSmallArray_32 {
    std::int32_t capacity;
    union {
        void* heapData;
        std::uint8_t localData[32];
    };
    std::uint32_t size;
    void* Data() {
        return (capacity < 0) ? static_cast<void*>(localData) : heapData;
    }
};

extern "C" void __cdecl ArrayMove_ce0980(std::uint32_t* sizePtr, void* data, std::uint32_t dstIdx, std::uint32_t srcIdx, std::uint32_t count, std::uint32_t elemSize);

struct BSTSmallArrayEraseOrdered {
    static void Op2fe700(BSTSmallArray_8* self, std::uint32_t pos, std::uint32_t count);
    static void Op5c2fa0(BSTSmallArray_8* self, std::uint32_t pos, std::uint32_t count);
    static void Op5eb880(BSTSmallArray_16* self, std::uint32_t pos, std::uint32_t count);
    static void Op771f30(BSTSmallArray_32* self, std::uint32_t pos, std::uint32_t count);
    static void Op873dd0(BSTSmallArray_32* self, std::uint32_t pos, std::uint32_t count);
    static void Op924e40(BSTSmallArray_16* self, std::uint32_t pos, std::uint32_t count);
    static void Opbdb950(BSTSmallArray_24* self, std::uint32_t pos, std::uint32_t count);
    static void Opce31b0(BSTSmallArray_16* self, std::uint32_t pos, std::uint32_t count);
};
