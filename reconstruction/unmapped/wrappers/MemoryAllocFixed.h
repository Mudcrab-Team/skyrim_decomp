// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryAllocFixed, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
}

struct MemoryFactoryManager {
    static void* GetSingleton() {
        if (MemMgrGuard_369ac98 != 2u) {
            MemMgrEnsure_cde810(MemMgrInst_369a810, &MemMgrGuard_369ac98);
        }
        return MemMgrInst_369a810;
    }
    static void* Alloc(std::size_t size, std::uint32_t align = 0u, bool alignReq = false) {
        return MemMgrAlloc_cde250(GetSingleton(), size, align, alignReq);
    }
};

struct MemoryAllocFixed {
    static void* Op1479a0();
    static void* Op1de620();
    static void* Op216570();
    static void* Op2165b0();
    static void* Op38c700();
    static void* Op38c740();
    static void* Op408fc0();
    static void* Op4aa160();
    static void* Op636cb0();
    static void* Op6440e0();
    static void* Op76b100();
    static void* Op992da0();
    static void* Opcd2ea0();
    static void* Opf02ab0();
    static void* Op1081f80();
    static void* Op10bf2e0();
    static void* Op1521e50();
};
