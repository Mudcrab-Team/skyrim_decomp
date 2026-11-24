// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateObject5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
    extern std::uint8_t Data_1915648[1];
    extern std::uint8_t Data_19849a8[1];
    extern std::uint8_t Data_19849b8[1];
    extern std::uint8_t Data_1a998a0[1];
    extern std::uint8_t Data_1ac49c0[1];
    extern std::uint8_t Data_1ac4e48[1];
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

struct HeapAllocBase {
    static void* operator new(std::size_t size) throw() {
        return MemoryFactoryManager::Alloc(size);
    }
};

struct Obj_98d470 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0x16];
    Obj_98d470() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_19849a8;
    }
};

struct Obj_98d600 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0xe];
    std::uint64_t f_18;
    Obj_98d600() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_19849b8;
        f_18 = 0u;
    }
};

struct Obj_ee9af0 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_ee9b50 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_ee9bb0 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_f7e0d0 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_fed2a0 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_fed300 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_1168e00 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0x6];
    std::uint64_t f_10;
    Obj_1168e00() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_1a998a0;
        f_10 = 0u;
    }
};

struct Obj_1168f20 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0x6];
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint32_t f_20;
    std::uint8_t unk_24[0x4];
    Obj_1168f20() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_1915648;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
};

struct Obj_12185b0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_12185b0() {
        f_8 = 0u;
        f_0 = Data_1ac49c0;
    }
};

struct Obj_121aeb0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0xc];
    Obj_121aeb0() {
        f_8 = 0u;
        f_0 = Data_1ac4e48;
    }
};

struct MemoryCreateObject5 {
    void* Op98d470();
    void* Op98d600();
    static void* Opee9af0();
    static void* Opee9b50();
    static void* Opee9bb0();
    static void* Opf7e0d0();
    static void* Opfed2a0();
    static void* Opfed300();
    void* Op1168e00();
    void* Op1168f20();
    void* Op12185b0();
    void* Op121aeb0();
};
